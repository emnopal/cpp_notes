#include <iostream>
#include <math.h>
#define h 1
#define pi 3.141592653589793238462643383279502884
using namespace std;

double fungsi(double x){
    return exp(-0.5 * x) * (4 - x) - 2;
}

double turunantengah(double x){
    return (fungsi(x+h) - fungsi(x-h))/2*h;
}

int main(){
    cout << turunantengah(4);
    return 0;
}