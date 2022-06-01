#include <iostream>

double pows(float number, int power){
    int p = 1;
    for (int i = 0; i <= power; i++){
        p = p * number;
    }
    return p;
}

unsigned long int fac(int number){
    int fact = 1;
    for (int i = 1; i <= number; i++){
        fact = fact * i;
    }
    return fact;
}

double exponential(int x, int itteration = 3){
    double exp = 0;
    for (int i = 0; i < itteration; i++){
        exp += (pows(x,i)/fac(i));
    }
    return exp;
}

int main(){
    int x = 45;
    std::cout << exponential(x);
    return 0;
}

