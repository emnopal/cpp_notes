#include <iostream>
#include <string>

using namespace std;
class transistor
{
    string namaa;
    string kdktr;
    int betaa;
    public:
    transistor(string namaaa, string kndktr, int betaaa) //constructor
    :namaa{namaaa}, kdktr{kndktr}, betaa{betaaa}{}; //setter
    string nama(){return namaa;}; // getter
    string jenis(){return kdktr;}; // getter
    int const beta();              // getter
    int darlington(transistor& b);
};

int transistor::darlington(transistor& b)
{
    int betaD;
    if(kdktr==b.kdktr) // == berarti "sama dengan"
    {
        if(namaa==b.namaa)
        {
            betaD = 1 + betaa*b.betaa;
            return betaD;
        }
        else return 0;
    }
    else return 0;
}

int const transistor::beta()
{
    if (betaa>=150 && betaa <= 450) // && berarti "dan"
    {                               // jika keduanya benar akan menjalankan if
        return betaa;
    }
    else return 0;
}

int main()
{
    cout << "input nilai beta transistor A = ";
    int beta;
    cin >> beta;
    cout << "input nama transistor A = ";
    string nama;
    cin >> nama;
    cout << "input jenis transistor A = ";
    string kdktr;
    cin >> kdktr;
    transistor A(nama,kdktr,beta);
    cout << "nama : " << A.nama() << endl;
    cout << "jenis konduktor : " << A.jenis() << endl;
    if (A.beta()!=0) cout << "nilai beta : " << A.beta() << endl;
    // != berarti "selain"
    else cout << "nilai beta diluar batas" << endl;
    cout << endl;
    cout << "input nilai beta transistor B = ";
    int betaB;
    cin >> betaB;
    cout << "input nama transistor B = ";
    string namaB;
    cin >> namaB;
    cout << "input jenis transistor B = ";
    string kdktrB;
    cin >> kdktrB;
    transistor B(namaB, kdktrB, betaB);
    cout << "nama : " << B.nama() << endl;
    cout << "jenis konduktor : " << B.jenis() << endl;
    if (B.beta()!=0) cout << "nilai beta : " << B.beta() << endl;
    else cout << "nilai beta diluar batas" << endl;
    cout << endl;
    if ((A.beta()==0)||(B.beta()==0)) cout << "tidak dapat menghitung beta darlington";
    // || berarti "atau", jika salah satu benar maka if akan berjalan
    else cout << "beta darlington = " << A.darlington(B);
    return 0;
}