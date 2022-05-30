#include <iostream>
using namespace std;
// * menujukkan nilai yang ditunjukkan oleh suatu variabel
// contoh int *p = new int (n) jadi si p tanpa bintang menunjukkan alamat di memori
// kalo si *p menunjukkan nilai dari p tersebut 

int main(){
    int* p1 = new int(7);
    double* p2 = new double(7);
    int* p3 = new int(64);
    double* p4 = new double(128);
    int* p5 = new int[0];
    double* p6 = new double[64];
    p6[0] = 5;
    p6[1] = 6;
    p6[4] = 7;
    int x2 = p6[0];
    int x3 = *p6;
    cout << p1 << " " << *p1 << " " << p2 << " " << *p2 << " ";
    cout << p3 << " " << *p3 << " " << p4 << " " << *p4 << " ";
    cout << p6 << " " << *p6 << " " << p5 << " " << *p5 << " ";
    cout << p6[0] << " "
         << " " << p6[1] << " " << p6[2] << " " << p6[0] << " "
         << " " << p6[1] << " " << p6[4] << " " << " " ;
    cout << endl;
}