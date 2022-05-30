#include <iostream>
using namespace std;

class vector{
    int sz;
    double *elem;
public:
    vector(int s) :sz(s),elem(new double[s]){}
    double get(int n) const {return elem[n];}
    void set(int n, double v) {elem[n]=v;}
    int size() const {return sz;}
};

int main(int argc, char** argv[]){
    vector v(10000000);
    for (int i = v.size(); i > -1; --i){
        v.set(i,i); //mengisi elemen ke i pada nomor ke i
        cout << v.get(i) << ' ';
    }
}