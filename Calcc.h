#include <std_lib_facilities.h>

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

void Token_stream::putback(Token t){ //manggil function tapi gaada outputnya atau nilainya; t itu input parameter
    if(full) error("putback() into a full buffer");
    buffer=t;
    full=true;
}

Token Token_stream::get(){
    if(full){
        full = false; return buffer;
    }
    char ch;
    cin >> ch;
    switch(ch){
        case '(':case ')':case ';': case 'q':case '+':case '-':case '*':case '/':
        return Token{ch};
    case'.':
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':{
        cin.putback(ch);
        double val;
        cin >> val;
        return Token{'8', val};
    }
    default:
        error("Bad token");
    }
}

double primary();

/* Fungsi Term */
double term(){
    double left = primary();
    while(true){
        Token t = ts.get();
        switch(t.kind){
            case '*': left *= primary(); 
            break;
            case '/':{
                double d = primary(); 
                if (d==0) error("heh antum salah! mana ada pembagian 0"); 
                left /= d; 
                break;
                }
            /*case '%';
            left %= primary();
            break;*/
            default:
            ts.putback(t);
            return left;
        }
    }
}

double expression();
/* Fungsi Primary */
double primary(){
    Token t = ts.get();
    switch(t.kind){
        case '(':{
            double d = expression();
            t = ts.get();
            if(t.kind != ')') error("')'expected");
            return d;
        }
    case '8':
        return t.value;
    default:
        error("primary expected");
    }
}

/* Fungsi Expression */
double expression(){
    double left = term();
    while(true){
        Token t = ts.get();
        switch (t.kind){
            case '+': left += term(); 
            break;
            case '-': left -= term(); 
            break;
            default:
            ts.putback(t);
            return left;
        }
    }
}

double term();
double primary();

int calculate(){
    double val = 0;
    cout << "> ";
    while(cin){
        Token t = ts.get();
        if(t.kind == 'q') break;
        if(t.kind == ';')
            cout << "= " << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
}