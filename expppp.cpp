#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int i;
    long double a = 0;
    while(i <= 10){
        a = exp(i);
        cout << i << ". " << a << endl;
        i++;
    }
    return 0;
}