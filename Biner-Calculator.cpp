#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int pangkat(int x, int y){
    int power = 1;
    for (int i = 0; i < y; i++){
        power = power * x;
    }
    return power;
}

int btd(long long n){
    int dec = 0, i = 0, sisa;
    while (n != 0){
        sisa = n % 10;
        n = n / 10;
        dec = dec + sisa * pangkat(2,i);
        ++i;
    }
    return dec;
}

long long dtb(int n){
    long long dec = 0;
    int sisa, i = 1, langkah = 1;
    while (n!=0){
        sisa = n%2;
        cout << "Langkah " << langkah++ << ": " << n << "/2, Sisa = " << sisa << ", Hasil Bagi = " << n/2 << endl;
        n /= 2;
        dec += sisa*i;
        i *= 10;
    }
    return dec;
}

int main()
{
    long long n;
    int a;
    cout << "1. Biner ke Desimal" << endl;
    cout << "2. Desimal ke Biner" << endl;
    cout << "Pilih: " << endl;
    cin >> a;
    if (a == 1){
        cout << "Masukan bilangan biner: ";
        cin >> n;
        cout << n << " biner = " << btd(n) << " desimal";
    }
    if (a == 2){
        cout << "Masukan bilangan desimal: ";
        cin >> n;
        cout << n << " desimal = \n" << dtb(n) << " biner";
    }
    return 0;
}

