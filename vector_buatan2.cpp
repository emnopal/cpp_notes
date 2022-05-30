#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class vector {
	int sz;		// the size
	double* elem;	// a pointer to the elements
public:
    vector(int s);                              	// constructor (s is the element count)
    vector(std::initializer_list<double> lst);      // initializer-list constructor
    vector(const vector&) ;                         // copy constructor: define copy (below)
    vector& operator=(const vector& a);             // copy assignment: define copy (below)

    double get(int n) const { return elem[n]; } 	// access: read
	void set(int n, double v) { elem[n]=v; }		// access: write
	int size() const { return sz; }			// the current size
    ~vector()		// destructor: de-allocates/releases memory
		{ delete[ ] elem;}
};


vector::vector(int s)	// constructor (s is the element count)
	:sz{s}, elem{new double[s]}
{
	for (int i=0; i<sz; ++i) elem[i]=0;
}

vector::vector(std::initializer_list<double> lst)   // initializer-list constructor
	:sz{lst.size()}, elem{new double[sz]}
{
    std::copy(lst.begin(),lst.end(),elem); // copy lst to elem
}

//=========================copy constructor=============================//
 vector::vector(const vector& a)
 	:sz{a.sz},  elem{new double[a.sz]}
 	// allocate space for elements, then initialize them (by copying)
 {
 	for (int i = 0; i<sz; ++i) elem[i] = a.elem[i];
 }

//=========================copy assignment=============================//
vector& vector::operator=(const vector& a)
	// like copy constructor, but we must deal with old elements
	// make a copy of a then replace the current sz and elem with a's
{
	double*p = new double[a.sz];			// allocate new space
	for (int i = 0; i<a.sz; ++i) p[i] = a.elem[i];	// copy elements
	delete[ ] elem;				// deallocate old space
	sz = a.sz;					// set new size
	elem = p;					// set new elements
	return *this; 		//  return a self-reference
				// The this pointer is explained in Lecture 19
				// and in 17.10
}

int main()
{

    ////////////////////////copy constructor////////////////////////////
    vector v3{5,2,1,20};
    cout << v3.size() << endl;
    cout << "get(3) v3 = " << v3.get(3) << endl;
    vector v4 = v3;
    cout << v4.size() << endl;
    cout << "get(3) v4 = " << v4.get(3) << endl;

    //////////////////////////copy assignment////////////////////////////
    vector v1{6,24,42}; //initializer list
	vector v2(4);
    cout << v2.size() << endl;
	v2 = v1;		// assignment
    cout << v1.size() << endl;
    cout << v2.size() << endl;
    cout << v1.get(1) << endl;
    cout << v2.get(1) << endl;
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2.get(i) << "  ";
    }
    cout << endl;

    return 0;
}