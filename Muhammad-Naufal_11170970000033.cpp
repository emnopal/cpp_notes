#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::initializer_list;
using std::istream;


class vector{
    int sz;
    double *elem;
public:
    vector(vector&&);
    vector(int s);
    vector(initializer_list<double> lst);
    vector(const vector&);
    vector& operator=(const vector& a);
    vector& operator=(vector&& a);
    double get(int n) const { return elem[n]; }
    void set(int n, double v) { elem[n] = v; }
    int size() const { return sz; }
    ~vector() { delete[] elem; }
    void fill();
};

vector::vector(int s) : sz(s), elem(new double[s]){
    for (int i = 0; i < sz; ++i)
        elem[i] = 0;
}

vector::vector(initializer_list<double> lst) : sz(lst.size()), elem{new double[sz]}{
    std::copy(lst.begin(), lst.end(), elem);
}

vector::vector(const vector &a) : sz{a.sz}, elem{new double[a.sz]}{
    for (int i = 0; i < sz; ++i)
        elem[i] = a.elem[i];
}

vector &vector::operator=(const vector &a){
    double *p = new double[a.sz]; 
    for (int i = 0; i < a.sz; ++i)
        p[i] = a.elem[i]; 
    delete[] elem;        
    sz = a.sz;            
    elem = p;             
    return *this;         
}

vector::vector(vector&& a) : sz{a.sz}, elem{a.elem}{
    a.sz = 0;
    a.elem = nullptr;
}

vector& vector::operator=(vector&& a){
    delete[] elem;
    elem = a.elem;
    sz = a.sz;
    a.elem = nullptr;
    a.sz = 0;
    return *this;
}

void vector::fill(){
    cout << "Elements that you wanna add to fill(): ";
    int n;
    cin >> n;
    sz = sz + n;
    double *pt = new double[sz];
    int oldsize = sz - n;
    for (int i = 0; i < oldsize; i++)
    {
        pt[i] = elem[i];
    }
    cout << "Enter that elements: ";
    for (int i = oldsize; i < sz; i++)
    {
        cin >> pt[i];
    }
    elem = pt;
}

int main(){
    vector vec{1,2,3};
    cout << "Vector before fill():\n";
    for (int i = 0; i < vec.size(); i++){
        cout << vec.get(i) << "  ";
    }
    cout << endl;
    vec.fill();
    cout << "Vector after fill():\n";
    for (int i = 0; i < vec.size(); i++){
        cout << vec.get(i) << "  ";
    }
    return 0;
}