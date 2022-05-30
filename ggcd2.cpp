#include <iostream>
#include <stdio.h>
#define size 10
using namespace std;

int gcd(int a, int b){
    if (b == 0 && a > b)
        return a;
    if (a > b && b != 0)
        return gcd(b, a % b);
    if (a < b)
        return gcd(b, a);
}

int ggcd(int *ggcd, int number){
    int c;
    if (number > 2){
        for (int j = 0; j < number - 2; j++){
            for (int k = 1; k < number - 1; k++){
                if (c < gcd(ggcd[j], ggcd[k])){
                    c = gcd(ggcd[j], ggcd[k]);
                }
            }
        }
    }
    if (number == 2){
        c = gcd(ggcd[0], ggcd[1]);
    }
    if (number < 2){
        printf("angka yang dimasukkan terlalu sedikit");
    }
    if (number > 1000000000){
        printf("angka yang dimasukkan terlalu besar");
    }
    cout << c << " ";
    c = 0;
    cout << "\n";
}

int main(){
    int cases, number;
    cout << "masukkan kasus: ";
    cin >> cases;
    if (cases < 1){
        return printf("kasus terlalu kecil, minimal 1\n");
    }
    if (cases > 100){
        return printf("kasus terlalu banyak, maksimal 100\n");
    }
    for (int i = 0; i < cases; i++){
        cout << "Kasus ke-" << i + 1 << " : \n";
        cout << "masukkan angka: ";
        cin >> number;
        if (number < 2){
            return printf("angka terlalu sedikit, minimal 3\n");
        }
        if (number > 100){
            return printf("angka terlalu banyak, maksimal 100\n");
        }
        cout << "masukkan angka dari FPB: ";
        int *ggcd2 = new int[size];
        for (int j = 0; j < number; j++){
            cin >> ggcd2[j];
        }
        ggcd(ggcd2, number);
    }
    return 0;
}
