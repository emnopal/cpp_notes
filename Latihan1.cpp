#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
    int a, b, c, d;
    cout << "masukkan nilai a = ";
    cin >> a;
    cout << "masukkan nilai b = ";
    cin >> b;
    cout << "masukkan nilai c = ";
    cin >> c;
    d = b * b - 4 * a * c;
    cout << "d = " << d << endl;
    if (d < 0)
        cout << "Akar Imajiner" << endl;
    else if (d == 0)
        cout << "Akar Real dan Kembar" << endl;
    else if (d > 0)
        cout << "Akar Real dan Beda" << endl;
return 0;
}