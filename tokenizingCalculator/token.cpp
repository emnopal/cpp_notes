#include <iostream>
#include "token.hpp"
#include "tokenException.hpp"

class TokenUse: public TokenStream {

    private:
        bool full;
        Token buffer;

    public:

        void putback(Token t){

            if(full) {
                throw std::invalid_argument("putback() into a full buffer");
            }

            setBuffer(t);
            buffer = getBuffer();

            setIsTokenFull(true);
            full = getIsTokenFull();
        }

        Token parse_token(char ch){

            switch(ch) {
                case '(':
                case ')':
                case ';':
                case 'q':
                case '+':
                case '-':
                case '*':
                case '/':{
                    return Token{ch};
                }

                case '.':
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':{
                    std::cin.putback(ch);
                    double val;
                    std::cin >> val;
                    return Token{'8', val};
                }

                default:{
                    throw std::invalid_argument("Bad token");
                }

            }
        };

        Token get() {

            if(full) {
                full = false;
                return buffer;
            }

            char ch;
            std::cin >> ch;

            return parse_token(ch);

        }

        double expression() {

            double left = term();

            while(true) {

                Token t = get();

                switch (t.kind){

                    case '+':
                        left += term();
                        break;

                    case '-':
                        left -= term();
                        break;

                    default:
                        putback(t);

                    return left;
                }

            }

        }

        double primary() {

            Token t = get();

            switch(t.kind) {

                case '(': {
                    double d = expression();
                    t = get();
                    if (t.kind != ')') {
                        throw std::invalid_argument("')'expected");
                    }
                    return d;
                }

                case '8':
                    return t.value;

                case ';':
                case ':':
                    return expression();

                case 'q':
                    return 0;

                default:
                    throw std::invalid_argument("primary expected");

            }
        }

        double term() {

            double left = primary();

            while(true){

                Token t = get();

                switch(t.kind){

                    case '*':
                        left *= primary();
                        break;

                    case '/':{
                        double d = primary();

                        if (d==0) {
                            throw std::invalid_argument("divided by zero");
                        }

                        left /= d;
                        break;
                    }

                    default:
                        putback(t);
                        return left;
                }
            }
        }

        void calculate() {

            double val = 0;
            std::cout << "> ";

            while(std::cin){
                Token t = get();

                if(t.kind == 'q'){
                    break;
                }

                if(t.kind == ';'){
                    std::cout << std::fixed << "= " << val << std::endl;
                }

                putback(t);

                val = expression();
            }
        }

};

int main(){
    std::cout << "kalkulator C++\n";
    std::cout << "\n";
    TokenUse *calculate = new TokenUse();
    try {
        calculate->calculate();
    } catch (ExceptionWhenEndOfCalculation e) {
        calculate->calculate();
    }
}
