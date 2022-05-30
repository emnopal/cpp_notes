#include <iostream>

using namespace std;
class vector {
	int sz;		// the size
	double* elem;	// a pointer to the elements
public:
    vector(int s);                              	// constructor (s is the element count)
    vector(std::initializer_list<double> lst);      // initializer-list constructor
    vector(const vector&) ;                         // copy constructor: define copy (below)
    vector& operator=(const vector& a);             // copy assignment: define copy (below)
    vector(vector&&);                               // move constructor: “steal” the elements
    vector& operator=(vector&& a);         // move assignment: destroy target and “steal” the elements

    double get(int n) { return elem[n]; }           // access: read
	void set(int n, double v) { elem[n]=v; }        // access: write
	int size() { return sz; }                       // the current size
    void fill();
    ~vector()		                                // destructor: de-allocates/releases memory
		{ delete[ ] elem; }
};

vector::vector(int s)	                            // constructor (s is the element count)
	:sz{s}, elem{new double[s]}
{
	for (int i=0; i<sz; ++i) elem[i]=0;
}

vector::vector(std::initializer_list<double> lst)   // initializer-list constructor
	:sz{lst.size()}, elem{new double[sz]}
{
    std::copy(lst.begin(),lst.end(),elem);          // copy lst to elem
}

vector::vector(const vector& a)
 	:sz{a.sz},  elem{new double[a.sz]}
 	// allocate space for elements, then initialize them (by copying)
{
 	for (int i = 0; i<sz; ++i) elem[i] = a.elem[i];
}

vector& vector::operator=(const vector& a)
	// like copy constructor, but we must deal with old elements
	// make a copy of a then replace the current sz and elem with a's
{
	double* p = new double[a.sz];			// allocate new space
	for (int i = 0; i<a.sz; ++i) p[i] = a.elem[i];	// copy elements
	delete[ ] elem;				// deallocate old space
	sz = a.sz;					// set new size
	elem = p;					// set new elements
	return *this; 		//  return a self-reference
				// The this pointer is explained in Lecture 19
				// and in 17.10
}

vector::vector(vector&& a)	// move constructor
   :sz{a.sz}, elem{a.elem}	// copy a's elem and sz
{
   a.sz = 0;               	// make a the empty vector
   a.elem = nullptr;
}

vector& vector::operator=(vector&& a)	// move assignment
{
   delete[] elem;		// deallocate old space
   elem = a.elem; 	// copy a's elem and sz
   sz = a.sz;
   a.elem = nullptr;	// make a the empty vector
   a.sz = 0;
   return *this;       	// return a self-reference (see §17.10)
}

void vector::fill()
{
    cout << "jumlah elemen yang ditambah : ";
    int n;
    cin >> n;
    sz = sz + n;
    double* pt = new double[sz];
    int oldsize = sz - n;
    for (int i = 0; i < oldsize; i++)
    {
        pt[i] = elem[i];
    }
    for (int i = oldsize; i < sz; i++)
    {
        cin >> pt[i];
    }
    elem = pt;
}

int main()
{
    vector v1{2, 1, 7, 20};
    cout << "isi vector 1 :\n";
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.get(i) << "  ";
    }
    cout << endl;
    vector v2 = std::move(v1);
    
    cout << "isi vector 2 :\n";
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2.get(i) << "  ";
    }
    cout << endl;

    vector v3{6, 9, 42, 21, 30};
    cout << "isi vector 3 :\n";
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3.get(i) << "  ";
    }
    cout << endl;
    vector v4(27);
    v4 = std::move(v3);
    
    cout << "size vector 4 = " << v4.size() << endl;
    cout << "isi vector 4 :\n";
    for (int i = 0; i < v4.size(); i++)
    {
        cout << v4.get(i) << "  ";
    }
    cout << endl;
    
    vector vec{9,7,5};
    cout << "isi vector sebelum fill() :\n";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec.get(i) << "  ";
    }
    
    cout << endl;
    vec.fill();

    cout << "\nisi vector setelah fill() :\n";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec.get(i) << "  ";
    }
    
    return 0;
}