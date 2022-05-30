#include "token.cpp"

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

int main(){
    cout << "kalkulator C++\n";
    cout << "Nama: Muhammad Naufal\n";
    cout << "NIM: 11170970000033\n";
    cout << "\n";
    return calculate();
}