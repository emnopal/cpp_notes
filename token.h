#include "std_lib_facilities.h"

struct Token{
    char kind; // char harus pake ''
    double value;
};

class Token_stream{
// Interface
public: // Tipe Member, bisa diluar class
    Token get(); // Function ada tanda kurung ()
    void putback(Token t); // Function
// Representation
private: // Tipe Member, hanya bisa diakses didalam class
    bool full {false};
    Token buffer;
};
Token_stream ts; // deklarasiin si ts.get

