#include<iostream>
#include <math.h>
#define EPSILON 0.1
#define h 1
using namespace std;

double func(double x){
	return exp(-0.5*x)*(4-x)-2;
}

double derivFunc(double x){
    return (func(x + h) - func(x - h)) / 2 * h;
}

void newtonRaphson(double x){
	double ha = func(x) / derivFunc(x);
	while (abs(h) >= EPSILON) {
		ha = func(x)/derivFunc(x);
		x = x - ha;
	}
	cout << "The value of the root is : " << x;
}

int main(){
	double x0 = 4;
	newtonRaphson(x0);
	return 0;
}
