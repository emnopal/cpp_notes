#include <iostream>
using std::cout;
using std::cin;
using std::endl;

double pows(float number, int power){
    int p = 1;
    for (int i = 0; i <= power; i++){
        p = p * number;
    }
    return p;
}

double fac(int number){
    int fact = 1;
    for (int i = 1; i <= number; i++){
        fact = fact * i;
    }
    return fact;
}

double exponential(int x, int itteration){
    double exp = 0;
    for (int i = 0; i < itteration; i++){
        exp = exp + (pows(x,i)/fac(i));
    }
    return exp;
}

int main(){
    int itteration;
    int x = 1;
    cout << "enter itteration: ";
    cin >> itteration;
    cout << exponential(x,itteration);
    return 0;
}

