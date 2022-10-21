#include <iostream>
#include <algorithm>
#include "polynomial.h"

using namespace std;

polynomial::polynomial(int stopien, double arr[]){
	degree = stopien;
	for(int i=0; i<100000; i++){
		if(i<=degree)
			coeff[i] = arr[i];
		else
			coeff[i] = 0;
	}

}
polynomial::polynomial(){
	this->degree=0;
	for(int i=0; i<100; ++i)
		this->coeff[i]=0;
}
polynomial polynomial::operator+(const  polynomial & k){
	polynomial w;
	w.degree=max(this->degree, k.degree);
	for(int i=0; i<100; ++i)
		if(i<=w.degree)
			w.coeff[i] = this->coeff[i]+k.coeff[i];
		else
			w.coeff[i]=0;
	return w;
}

void polynomial::display(){
	for(int i=0; i<=degree; ++i){
		if(i!=degree)
			cout<<coeff[i]<<"*x^"<<i<<" + ";
		else
			cout<<coeff[i]<<"*x^"<<i<<endl;
	}

}

polynomial polynomial::operator-(const  polynomial & k){
	polynomial w;
	w.degree=max(this->degree, k.degree);
	for(int i=0; i<100; ++i)
		if(i<=w.degree)
			w.coeff[i] = this->coeff[i]-k.coeff[i];
		else
			w.coeff[i]=0;
	return w;

}

polynomial polynomial::operator*(const polynomial & k){

	polynomial w;
	w.degree=this->degree+k.degree;
	
	for(int i=0; i<=this->degree; ++i){
	
		for(int j=0; j<=k.degree; ++j)
			w.coeff[i+j] += this->coeff[i]*k.coeff[j];
	}
	
	return w;
}

double polynomial::calculate(double x){
	double b = coeff[degree];
	for(int i=degree-1; i>=0; i--)
		b=coeff[i] + b*x;
	return b;
}

bool polynomial::operator==(const polynomial & k){
	bool isEqual = true;
	for(int i=0; i<100; i++)
		if(this->coeff[i]!=k.coeff[i])
			isEqual=false;
		
	return isEqual;
}

void polynomial::operator=(const polynomial & k){
	this->degree=k.degree;
	for(int i=0; i<100; ++i)
		this->coeff[i]=k.coeff[i];
}
