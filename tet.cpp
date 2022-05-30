#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t = 24, h = 6, i;
    long double a;
    while(i <= t){
        a = exp(-t*log10(2/h));
        cout << i << ". " << a << endl;
        i++;
    }
    return 0;
}