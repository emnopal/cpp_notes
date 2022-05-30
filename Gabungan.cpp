#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class Electronics{ // Class dari Electronics
private: // private member dari class Electronics
    string Trans,Semi;
    int B,b,a;
public: // public member dari class Electronics
    Electronics(string Transistor, string Semiconductor, int Beta){ // Constructor
        Trans = Transistor;
        Semi = Semiconductor;
        B = Beta;
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
        cout << Trans;
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

int Darlington(int b, int a){
    int d;
    d = a + a * b + b;
    cout << "Beta Darlington dari Data Pertama dan Data Kedua: " << d;
    return d;
}

double pows(float number, int power){
    int p = 1;
    for (int i = 0; i <= power; i++){
        p = p * number;
    }
    return p;
}

float pi(int iteration){
    float pie = 0;
    for (int i = 0; i < iteration; i++){
        pie = pie + (-4 * pows(-1, i) / (2*i + 1));
    }
    return pie;
}

int main(){
    cout << "Nomor 1: \n";
    int a, b, c, d;
    cout << "masukkan nilai a = ";
    cin >> a;
    cout << "masukkan nilai b = ";
    cin >> b;
    cout << "masukkan nilai c = ";
    cin >> c;
    d = b * b - 4 * a * c;
    cout << "d = " << d << endl;
    if (d < 0)
        cout << "Akar Imajiner" << endl;
    else if (d == 0)
        cout << "Akar Real dan Kembar" << endl;
    else if (d > 0)
        cout << "Akar Real dan Beda" << endl;
    cout << "\nNomor 2: \n";
    cout << setprecision(7) << pi(20000) << endl;
    cout << "\nNomor 3: \n";
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
    Electronics ElectronicsA = Electronics(TransA, SemiA, BetaA);
    Electronics ElectronicsB = Electronics(TransB, SemiB, BetaB);
    if (ElectronicsA.getSemi() == ElectronicsB.getSemi()){
        cout << "------------------- HASIL ------------------------------";
        cout << "\nData Pertama: ";
        ElectronicsA.Data();
        cout << endl;
        cout << "Data Kedua: ";
        ElectronicsB.Data();
        cout << endl;
        Darlington(BetaA, BetaB);
        cout << endl;
        cout << "--------------------------------------------------------";
        cout << endl;
    }
    else{
        cout << "------------------- HASIL -----------------------";
        cout << "\nData Pertama: ";
        ElectronicsA.Data();
        cout << endl;
        cout << "Data Kedua: ";
        ElectronicsB.Data();
        cout << endl;
        cout << "-------------------------------------------------";
        cout << endl;
    }
return 0;
}

/*if (ElectronicsA.getSemi() == ElectronicsB.getSemi()){
        cout << "------------------- HASIL ------------------------------";
        cout << endl;
        cout << "Beta Darlington dari transistor " << ElectronicsA.getTrans() << " dan " << ElectronicsB.getTrans() << " adalah: ";
        Darlington(BetaA, BetaB);
        cout << endl;
        cout << "--------------------------------------------------------";
        cout << endl;
    }
    else{
        cout << "------------------- HASIL -----------------------";
        cout << endl;
        cout << "Karena Jenis Semikonduktornya tidak sejenis\n";
        cout << "sehingga tidak bisa menghasilkan beta darlington";
        cout << endl;
        cout << "-------------------------------------------------";
        cout << endl;
    }*/