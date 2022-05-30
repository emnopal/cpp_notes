#include <iostream>
#include <cmath>
using namespace std;

int btd(long long n){
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0){
        remainder = n%10;
        n = n / 10;
        decimalNumber = decimalNumber + remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

int main()
{
    long long n;
    cout << "Enter a binary number: ";
    cin >> n;
    cout << n << " in binary = " << btd(n) << " in decimal";
    return 0;
}

