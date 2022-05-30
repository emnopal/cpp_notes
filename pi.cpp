#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
using std::cout;
using std::cin;
#define consts 12
#define moreconst 640320
#define damnconst 545140134
#define omgconst 13591409

float pows(float number, int power){
	int p = 1;
	for (int i = 0; i <= power; i++){
		p = p * number;
	}
	return p;
}

int fac(int number){
	int fact = 1;
	for (int i = 1; i <= number; i++){
		fact = fact * i;
	}
	return fact;
}

float pi(int k){
	float pii, pii1, pii2;
	float piitot = 0;
	for (int i = 1; i <= k; i++){
		pii1 = fac(3*i) * pows(fac(i), 3) * pows(moreconst, (3*i)+(3/2));
		pii2 = pows(-1, i) * fac(6*i) * (damnconst*i + omgconst) ;
		piitot = piitot + (pii2/pii1);
	}
	pii = (1/consts) * piitot;
	return pii;
}

int main(){
	float k;
	cout << "Itteration: ";
	cin >> k;
	cout << "for pi in " << k << " itteration is: " << pi(k); 
	return 0;
}
