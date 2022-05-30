#include <iostream>
#include <iomanip>
using namespace std;

double power(float x, float y){
    double pow = 1;
    for (int i = 0; i <= y; i++){
        pow = pow * x;
    }
    return pow;
}

float pi(int n){
    float pie = 0;
    for (int i = 0; i < n; i++){
        pie = pie + (-4 * power(-1, i) / (2*i + 1));
    }
    return pie;
}

int main(){
    cout << setprecision(64) << pi(2000);
    return 0;
}