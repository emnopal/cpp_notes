#include <iostream>
using namespace std;

double factorial(double n){
    int factorial = 1;
    for(int i = 1; i <= n; i++){
        factorial = factorial * i;
    }
    return factorial;
}

int main(){
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Factorial of " << n << " = " << factorial(n);
    return 0;
}