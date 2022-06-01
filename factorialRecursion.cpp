#include <iostream>

/*
use unsigned int since this is recursion
if too many recursion, will lead to overflow error
*/
unsigned int factorial(int n){
    return n <= 1 ? 1 : n * factorial(n - 1);
}

int main(){
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;
    std::cout << "Factorial of " << n << " = " << factorial(n);
    return 0;
}
