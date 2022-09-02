struct Token{
    char kind;
    double value;
};

class TokenStream
{

    private:

        bool full = false;
        Token buffer;

    public:

        // something like abstract class or interface

        // this is interface
        // since, in here there is another function
        // that doesn't need to implement, so
        // interface doesn't suitable for this cases
        // Token get();
        // void putback(Token t);
        // Token parse_token(char ch);
        // double expression();
        // double primary();
        // double term();
        // void calculate();

        // this is abstract class
        virtual Token get() = 0;
        virtual void putback(Token t) = 0;
        virtual Token parse_token(char ch) = 0;
        virtual double expression() = 0;
        virtual double primary() = 0;
        virtual double term() = 0;
        virtual void calculate() = 0;

        bool getIsTokenFull() {
            return full;
        }

        void setIsTokenFull(bool full) {
            this->full = full;
        }

        Token getBuffer() {
            return buffer;
        }

        void setBuffer(Token buffer) {
            this->buffer = buffer;
        }

};

