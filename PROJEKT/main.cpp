#include <iostream>
#include "polynomial.h"

using namespace std;

int main(){


	cout<<"--------------DZIALANIA NA WIELOMIANACH----------------"<<endl;
	cout<<"Wybierz numer aby wykonac konkretne dzialanie \n";
	cout<<"1. Oblicz wartosc wielomianu \n";
	cout<<"2. Odejmij od siebie dwa wielomiany \n";
	cout<<"3. Dodaj do siebie dwa wielomiany \n";
	cout<<"4. Przemnurz przez siebie dwa wielomiany \n";
	cout<<"5.Zakoncz program \n";
	int coeff;
	int c=1;
	double tab[3] = {1, 2, 1};
	polynomial p1(tab, 2);
	polynomial p2(tab, 2);
	/*while(c!=5){
		cout<<"Podaj numer dzialania \n";
		cin>>c;
		switch(c){
		
			case 1:{
				cout<<"Podaj stopien wielomianu, ktory chcesz obliczyc \n";
				cin>>coeff;
				double t[100];
				cout<<"Podaj wspolczynniki wielomianu \n";
				for(int i=0; i<coeff+1; i++)
					cin>>t[i];
				polynomial poly(t, coeff+1);
				cout<<"Podaj punkt w ktorym chcesz obliczyc wartosc wielomianu \n";
				double x;
				cin>>x;
				cout<<"wartosc wielomianu ";
				poly.display();
				cout<<" w punkcie "<<x<<" jest rowna "<<poly.calculate(x)<<endl;
				break;
				}
			case 2:{
				cout<<"Podaj stopien pierwszego wielomianu \n";
				cin>>coeff;
				double t2[100];
				cout<<"Podaj wspolczynniki wielomianu \n";
				for(int i=0; i<=coeff; ++i)
					cin>>t2[i];
				polynomial poly2(t2, coeff+1);
				cout<<"Podaj stopien drugiego wielomianu \n";
				cin>>coeff;
				double t3[coeff+1];
				cout<<"Podaj wspolczynniki wielomianu \n";
				for(int i=0; i<=coeff; ++i)
					cin>>t3[i];
				polynomial poly3(t3, coeff+1);/*
				polynomial result=poly2-poly3;
				poly2.display();
				cout<<"-";
				poly3.display();
				cout<<"=";
				result.display();
				break;
				}
			case 3:{
				cout<<"Podaj stopien pierwszego wielomianu \n";
				cin>>coeff;
				double tab[100];
				cout<<"Podaj wspolczynniki wielomianu \n";
				for(int i=0; i<=coeff; ++i)
					cin>>tab[i];
				polynomial poly(tab, coeff+1);
				cout<<"Podaj stopien drugiego wielomianu \n";
				cin>>coeff;
				double tab2[coeff+1];
				cout<<"Podaj wspolczynniki wielomianu \n";
				for(int i=0; i<=coeff; ++i)
					cin>>tab2[i];
				polynomial poly2(tab2, coeff+1);
				polynomial result=poly+poly2;
				poly.display();
				cout<<"-";
				poly2.display();
				cout<<"=";
				result.display();
				break;
			
			}
			case 4:{
				cout<<"Podaj stopien pierwszego wielomianu \n";
				cin>>coeff;
				double tab[100];
				cout<<"Podaj wspolczynniki wielomianu \n";
				for(int i=0; i<=coeff; ++i)
					cin>>tab[i];
				polynomial poly(tab, coeff+1);
				cout<<"Podaj stopien drugiego wielomianu \n";
				cin>>coeff;
				double tab2[coeff+1];
				cout<<"Podaj wspolczynniki wielomianu \n";
				for(int i=0; i<=coeff; ++i)
					cin>>tab2[i];
				polynomial poly2(tab2, coeff+1);
				polynomial result=poly*poly2;
				poly.display();
				cout<<"-";
				poly2.display();
				cout<<"=";
				result.display();
				break;
				
			}	

		
		}
	
	}*/

	return 0;
}
