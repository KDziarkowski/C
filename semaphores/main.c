#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include  <sys/stat.h>
#include <errno.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <semaphore.h>
#define NELE 40  
#define NBUF  15
void* create_shared_memory(size_t size) {

  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_SHARED | MAP_ANONYMOUS;

  return mmap(NULL, size, protection, visibility, -1, 0);
}
     
int main(int argc,char *argv[])
{	
	sem_t pro,kon;
	int value=2,value2=2;
	char bufor[21];
  sem_init(&pro,0,value);
  sem_init(&kon,0,value2);
  int plik, odczyt, zapis, plik2;
  struct SegmentPD {
  	char bufor[NBUF][NELE];  
	int  zapis;
	int odczyt;
	}; 
  struct SegmentPD *PD =(struct SegmentPD *) create_shared_memory(128);
  PD->zapis=0;
  PD->odczyt=0;
  printf("Udalo sie utworzyc pamiec dzielona \n");
  if((plik = open("odczyt.txt",O_RDWR, 0644))==-1)
  	 exit(1);
  if((plik2 = open("zapis.txt",O_RDWR, 0644))==-1)
  	 exit(1);
	printf("Udalo sie otworzyc plik tekstowy \n");
  int pid = fork();

  if (pid == 0) {
 	 while(1){
 	 sem_getvalue(&kon,&value2);
 	 printf("Konsument: przed SK semafor konsumenta: %d \n",value2);
    sem_wait(&kon);
    zapis = write(plik2, &bufor, 20);
    printf("%d, %s \n", zapis, bufor);
    if(zapis==-1){
    	printf("Blad zapisu do pliku");
    	exit(0);
    } else if(zapis==0){
    	strcpy(PD->bufor[PD->odczyt], "\0");
    	//break;
    	} else{
    		printf("przed kopiowaniem \n");
    		memcpy(bufor, PD->bufor[PD->odczyt],zapis);
    		PD->odczyt = (PD->odczyt +1)% NBUF;
    		printf("Konsumuje %s \n", bufor);
    		printf("Zapis w procesie konsumenta wynosi %d odczyt wynosi %d \n",zapis,odczyt);
    }
    
    sem_post(&pro);
    sem_getvalue(&pro,&value);
    printf("Konsument: przed SK semafor producenta: %d \n",value);
    printf("\n");
    }
  } else {
   while(1){
   sem_getvalue(&pro,&value);
   printf("Producent: przed SK semafor producenta: %d \n",value);
    sem_wait(&pro);
    odczyt = read(plik, &bufor, 20);
    printf("%d , %s \n", odczyt , bufor);
    if(odczyt==-1){
    	printf("Blad odczytu z pliku");
    	exit(0);
    } else if (odczyt==0){
      	strcpy (PD->bufor[PD->zapis], "\0");
      	//break;
      	} else{
      	
      	printf("przed kopiowaniem\n");
      	memcpy(PD->bufor[PD->zapis],bufor,odczyt);
      	PD->zapis = (PD->zapis +1)% NBUF;
      	printf("Produkuje %s \n", bufor);
      	printf("Zapis w procesie producenta wynosi %d odczyt wynosi %d \n",zapis,odczyt);
      	}
      	
    sem_post(&kon);
    sem_getvalue(&kon,&value2);
    printf("Producent: po SK semafor konsumenta: %d \n",value2);
    printf("\n");
    }
 
  }
}
