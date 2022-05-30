#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
    float v,s;
    for (int t = 1; t <= 100; t++){
        v = 2 + (t-1)*0.1;
        s = 2*t + 0.5*(v - 2)*t;
        cout << t << "   " << v << "    " << s << endl;
    }
    return 0;
}