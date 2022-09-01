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
        // virutal type func() = 0; <- avoiding undefined reference to vtable for BaseClass
        virtual Token get() = 0; // i don't know what is the meaning of this, but i think is this abstract class or interface?
        virtual void putback(Token t) = 0;
        bool getIsTokenFull(){
            return full;
        }
        void setIsTokenFull(bool full){
            this->full = full;
        }
        Token getBuffer(){
            return buffer;
        }
        void setBuffer(Token buffer){
            this->buffer = buffer;
        }

};

