#include <iostream>
#include <string.h>
using namespace std;

class Electronics{ // Class dari Electronics
private: // private member dari class Electronics
    string Trans,Semi;
    int B,Darlingtons;
public: // public member dari class Electronics
    Electronics(string Transistor, string Semiconductor, int Beta){ // Constructor
        Trans = Transistor;
        Semi = Semiconductor;
        B = Beta;
    }
    /*~Electronics(){ // Destructor
        cout << "\nDestructor" << endl;
        B = 0;
    }*/
    Electronics Darlington(Electronics Electronics1, Electronics Electronics2){ // Member Function dari Darlington
        Electronics::Darlingtons;
        if (Electronics1.getSemi() == Electronics2.getSemi()){
            Darlingtons = Electronics1.getB() * Electronics2.getB();
            cout << "Beta Darlington dari transistor " << Electronics1.getTrans() << " dan " << Electronics2.getTrans() << " adalah: " << Darlingtons;
            return *this;
        }
        else{
            cout << "Jenis Transistor tidak sama!"; 
            return *this;
        }
    }
    void Data(){ // Buat Nampilin Hasil ke Layar
        cout << endl;
        cout << "Nama Transistornya: " << Trans << endl;
        cout << "Nama Semikonduktornya: " << Semi << endl;
        cout << "Nilai Beta nya: " << B << endl;
    }
    void setTrans(string NewTransistor){ // Setter() dari Transistor
        NewTransistor = Trans;
    }
    void setSemi(string NewSemiconductor){   // Setter() dari SemiConductor
        NewSemiconductor = Semi;
    }
    void setB(int NewBeta){ // Setter() dari Beta
        NewBeta = B;
    }
    string getTrans(){ // Getter() dari Trans
        return Trans;
    }
    string getSemi(){ // Getter() dari Semi
        if (Semi == "pnp" || Semi == "npn" || Semi == "PNP" || Semi == "NPN"){
            return Semi;
        }
        else{
            string s1 = "error";
            cout << s1;
            return s1;
        }
    }
    int getB(){ // Getter() dari B
        return B;
    }
};

int main(){
    string Trans, Semi;
    int B;
    // Input Parameter
    cout << "Data Pertama: \n";
    cout << "Masukkan Nama Transistor: ";
    string TransA;
    cin >> TransA;
    cout << "Masukkan Jenis Semikonduktornya: ";
    string SemiA;
    cin >> SemiA;
    cout << "Masukkan nilai Beta nya: ";
    int BetaA;
    cin >> BetaA;
    cout << "\nData Kedua: \n";
    cout << "Masukkan Nama Transistor: ";
    string TransB;
    cin >> TransB;
    cout << "Masukkan Jenis Semikonduktornya: ";
    string SemiB;
    cin >> SemiB;
    cout << "Masukkan nilai Beta nya: ";
    int BetaB;
    cin >> BetaB;
    cout << endl;
    Electronics ElectronicsA = Electronics(TransA, SemiA, BetaA); // Deklarasi Konstruktor Data Pertama
    Electronics ElectronicsB = Electronics(TransB, SemiB, BetaB); // Deklarasi Konstruktor Data Kedua
    Electronics Count = Electronics(Trans, Semi, B);              // Deklarasi Konstruktor Sembarang, Gunanya untuk membandingkan 2 buah konstruktor diatas
    Count.Darlington(ElectronicsA, ElectronicsB);                 // Memamnggil Member Function Darlington
    return 0;
}