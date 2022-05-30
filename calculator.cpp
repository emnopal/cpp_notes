#include <iostream>
using namespace std;

/* Penjumlahan */
float penjumlahan(float a, float b){
    return a+b;
}

/* Pengurangan */
float pengurangan(float a, float b){
    return a-b;
}

/* Perkalian */
float perkalian(float a, float b){
    return a*b;
}

/* Pembagian */
float pembagian(float a, float b){
    return a/b;
}

int main(){
   int a = 200, b = 167;
   cout << penjumlahan(a,b) << endl;
   cout << pengurangan(a,b) << endl;
   cout << perkalian(a,b) << endl;
   cout << pembagian(a,b) << endl;
   return 0;
}
