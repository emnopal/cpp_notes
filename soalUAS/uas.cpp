#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class transistor
{
    string kdktr;
    string namaa;
    int betaa;
    public:
    transistor(string kind, string kndktr, int bt)    // constructor
        :namaa{kind}, kdktr{kndktr}, betaa{bt}{};     // getter
    void tampil_jenis();
    string nama(){return namaa;};                     // setter
    string jenis(){return kdktr;};                    // setter
    int const beta(){return betaa;};                  // setter
    int darlington(transistor& a);
};


int transistor::darlington(transistor& a)
{
    int betaD;
    if (kdktr==a.kdktr)
    {
        betaD = 1 + (betaa*a.betaa);
        return betaD;
    }
    else
    {
        return 0;
    }
}

void transistor::tampil_jenis()
{
    cout << "Nama = " << namaa <<endl;
    cout << "jenis semikonduktor = " << kdktr << endl;
    cout << "nilai beta = " << betaa << endl;
}
/////
    double pangkat(double x, int n)
    {
        double total = 1;
        if (n > 1)
        {
            for (int i = 0; i < n; i++)
            {
                total = total * x;
            }
            return total;
        }
        else
        {
        for (int i = n; i < 0; i++)
            {
            total = 1/(total * x);
            }
        return total;
        }
    }
/////

double pi(int kk)
{
    double sum = 0;
    // double Pi = 0;

    for (int k = 0; k <= kk; k++)
    {
        double pembagi = 2*k + 1;
        if (k % 2 == 0) sum += 1/pembagi; // k genap
        else sum -= 1/pembagi;            // k ganjil
        // double pembagi = 2*k + 1;
        // if (k % 2 == 0) Pi += 1/pembagi;
        // else Pi -= 1/pembagi;
    }
    double Pi = 4 * sum;
    // Pi *= 4;
    return Pi;
}


int main()
{
    // int a,b,c,d;
    // cout << "masukkan nilai a : ";
    // cin >> a;
    // cout << "masukkan nilai b : ";
    // cin >> b;
    // cout << "masukkan nilai c : ";
    // cin >> c;
    // d = b*b - 4*a*c;
    // cout << "d = " << d << endl;
    // if (d < 0) cout << "Akar Imajiner" << endl;
    // else if (d == 0) cout << "Akar Real dan Sama" << endl;
    // else if (d > 0) cout << "Akar Real dan beda" << endl;
    
    cout << "input nilai k : ";
    int k;
    cin >> k;
    cout << "nilai pi = " << setprecision(7) << pi(k) << endl;

    string smktr[2];
    string nama[2];
    int bt[2];
    for (int i = 0; i < 2; i++)
    {
        int nomor;
        int x = i + 1;
        cout << "pilih jenis transistor " << x << " :\n"
             << "1) NPN\n" << "2) PNP\n";
        do
        {
            cout<<"pilihan : ";cin>>nomor;
            switch (nomor){
                case 1:
                    smktr[i] = "NPN";
                    break;
                case 2:
                    smktr[i] = "PNP";
                    break;
                default:
                    cout << "input salah\n";
                    break;
            }
        } while ((nomor != 1) && (nomor != 2));
        cout << smktr[i] << " dengan nilai beta = ";
        cin >> bt[i];
        cin.get();
        cout << "Nama " << smktr[i] << " = ";
        cin >> nama[i];
        cout << endl;
    }
    transistor A(nama[0], smktr[0], bt[0]);
    transistor B(nama[1], smktr[1], bt[1]);
    cout << "Transistor 1 :\n";
    // A.tampil_jenis();
    cout << "Nama                = " << A.nama() << endl;
    cout << "jenis semikonduktor = " << A.jenis() << endl;
    cout << "nilai beta          = " << A.beta() << endl;
    
    if (A.jenis()==B.jenis())
    {
        cout << "Jika rangkaian dipakai dalam moda tunggal emitor maka Re = 0.\n";
        cout << "Beta Darlington = " << A.darlington(B);
    }
    else cout << "tidak dapat menghitung beta Darlington karena jenis semikonduktor berbeda";
    

    return 0;
}
// https://proofwiki.org/wiki/Leibniz's_Formula_for_Pi
// http://didar-physics.blogspot.com/2014/12/coding-leibniz-formula-for-via-c.html
// https://stackoverflow.com/questions/39987538/c-pi-approximation-using-leibniz-formula
// https://id.wikipedia.org/wiki/Transistor_Darlington
