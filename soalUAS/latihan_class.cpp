/*
Tipe class ada dua yaitu public dan private:
nah kalo public bisa diakses dari luar tapi kalo private gabisa diakses dari luar
kalo kita gak nulis tipe public atau private otomatis class nya jadi private
kalo struct (c) sama kaya class (c++), tapi isinya public semua <-- bedanya sama c dan c++
 */
#include <iostream>
using std::cout;
//kalo pake class (c++ model)
/*class x{
    public:
        int m;
    //private: kalo ini ada gabakal bisa diakses
        int mf(int v){
            int old = m; 
            m=v;
            return old;
        }
};*/

//kalo pake struct (c model)
struct x{
    //public: gausah pake public soalnya public semua
        int m;
        int mf(int v){
            int old = m; 
            m=v;
            return old;
        }
};

int main(){
    x var;
    var.m = 9;
    int x = var.mf(10);
    cout << x << "\n" << var.m;
}

