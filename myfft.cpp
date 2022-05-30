#include <iostream>
#include <complex>
#include <math.h>
#define pi 3.14159265358979323846
using namespace std;

int main(){
    int k,j;
    int x[1] = {25};
    int N = sizeof(x);
    const complex<double> i(0, 1);
    for (k = 1; k < N; k++){
        int y[k] = {0};
        for (j = 1; j < N; j++){
            y[k] += x[j]*exp(-i * 2*pi*[j-1]*[k-1]/N);
        }
    }
    return 0;
}