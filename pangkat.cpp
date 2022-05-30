#include <iostream>
using namespace std;

float square(int angka, int pangkat){
    float power = 1;
    for (int i = 0; i < pangkat; i++){
        power = power * angka;
    }
}

int main (){
    float angka, pangkat;
    cout << "Angka: ";
    cin >> angka;
    cout << "Pangkat: ";
    cin >> pangkat;
    cout << angka << " Pangkat " << pangkat << " = " << square(angka, pangkat);
}