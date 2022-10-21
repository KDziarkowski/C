#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include "main.h"
int main(int argc, char **argv)
{
    int fd[2];
    char input[30];
    char output[30];
    int r,in,out;
    if(pipe(fd)==-1){
        perror("Blad funkcji pipe");
        exit(1);
    }
    char*odczyt=argv[1];
    char*zapis=argv[2];
    if( (in = open(odczyt,O_RDWR, 0644))==-1) exit(1);
    if( (out = open(zapis,O_RDWR, 0644))==-1) exit(2);
    switch(fork()){
        case -1:
            perror("Blad funkcji fork");
            exit(1);
            break;
        case 0:
	 close(fd[1]);
	 
            while(read(fd[0],output,30)!=0){
            	
            	if(write(STDOUT_FILENO,"\n Reading from file : ",22)==-1) exit(0);
            	if(write(STDOUT_FILENO,output,30)==-1) exit(0);
                if(write(out, output,30)==-1) exit(0);
                printf("\n");
                srand(time(NULL)+1);
                int czas;
                czas= rand()%30 +30;
                sleep(czas/20);
            }
            break;
        default:

            close(fd[0]);

            while(r = read(in,input,30)!=0){
            	
                if(write(fd[1],input,30)==-1) exit(0);
                if(write(STDOUT_FILENO,"\n Writing to file : ",20)==-1) exit(0);
                if(write(STDOUT_FILENO,input,30)==-1) exit(0);
		//printf( "\n %d \n", r);
		
                srand(time(NULL)+1);
                int czas;
                czas= rand()%30 +30;
                sleep(czas/20);
            }
        break;

    };
    return(0);
}
