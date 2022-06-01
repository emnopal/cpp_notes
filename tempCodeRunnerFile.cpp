#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>

class Electronics
{

private:
    std::string Transistor, Semiconductor;
    int B,b,a,Beta;

public:

    Electronics(std::string &Transistor, std::string &Semiconductor, int &Beta){
        this->Transistor = Transistor;
        this->Beta = Beta;

        std::string semi = Semiconductor;
        std::transform(semi.begin(), semi.end(), semi.begin(), [](unsigned char c){ return std::tolower(c); });
        if (semi == "pnp" || semi == "npn"){
            this->Semiconductor = Semiconductor;
        }
        else{
            throw std::invalid_argument("Semiconductor tidak valid");
        }
    }

    void Data(){
        std::cout << std::endl;
        std::cout << "Nama Transistornya: " << this->Transistor << std::endl;
        std::cout << "Nama Semikonduktornya: " << this->Semiconductor << std::endl;
        std::cout << "Nilai Beta nya: " << this->Beta << std::endl;
    }

    void setTransistor(std::string &Transistor){
        this->Transistor = Transistor;
    }

    void setSemiconductor(std::string &Semiconductor){
        this->Semiconductor = Semiconductor;
    }

    void setBeta(int &Beta){
        this->Beta = Beta;
    }

    std::string getTrans(){
        return this->Transistor;
    }

    std::string getSemiconductor(){
        return this->Semiconductor;
    }

    int getBeta(){
        return this->Beta;
    }
};

int Darlington(int b, int a){
    int d = a + a * b + b;
    std::cout << "Beta Darlington dari Data Pertama dan Data Kedua: " << d;
    return d;
}

float pows(float number, int power){
    int p = 1;
    for (int i = 0; i <= power; i++){
        p *= number;
    }
    return p;
}

float pi(int iteration = 100){
    float pie = 0;
    for (int i = 0; i < iteration; i++){
        pie += (-4 * pows(-1, i) / (2*i + 1));
    }
    return pie;
}

template <typename T>
std::pair<float, std::string> getAkar(T a, T b, T c){
    float root = b * b - 4 * a * c;
    if (root == 0){
        return std::make_pair(root, "Akar Kembar");
    }
    if (root < 0){
        return std::make_pair(root, "Imajiner");
    }
    if (root > 0){
        return std::make_pair(root, "Real");
    }
    throw std::invalid_argument("Argument tidak valid");
}

class Jawaban
{
private:
    int Precision;

public:

    Jawaban(int Precision = 7){
        this->Precision = Precision;
    }

    void NomorSatu(){
        float a, b, c;
        std::pair<float, std::string> root;

        std::cout << "Nomor 1: \n";

        std::cout << "masukkan nilai a = ";
        std::cin >> a;
        std::cout << "masukkan nilai b = ";
        std::cin >> b;
        std::cout << "masukkan nilai c = ";
        std::cin >> c;

        root = getAkar(a, b, c);

        std::cout << "Hasil Akar: " << root.first
        << "Jenis Akar: " << root.second;
    }

    void NomorDua(){
        std::cout << "\n Nomor 1: \n";
        std::cout << std::setprecision(this->Precision) << pi() << std::endl;
    }

    void NomorTiga(){
        std::string TransA, SemiA, TransB, SemiB;
        int BetaA, BetaB;

        std::cout << "\nNomor 3: \n";
        std::cout << "Data Pertama: \n";
        std::cout << "Masukkan Nama Transistor: ";
        std::cin >> TransA;
        std::cout << "Masukkan Jenis Semikonduktornya: ";
        std::cin >> SemiA;
        std::cout << "Masukkan nilai Beta nya: ";
        std::cin >> BetaA;
        std::cout << "\nData Kedua: \n";
        std::cout << "Masukkan Nama Transistor: ";
        std::cin >> TransB;
        std::cout << "Masukkan Jenis Semikonduktornya: ";
        std::cin >> SemiB;
        std::cout << "Masukkan nilai Beta nya: ";
        std::cin >> BetaB;
        std::cout << std::endl;

        Electronics ElectronicsA = Electronics(TransA, SemiA, BetaA);
        Electronics ElectronicsB = Electronics(TransB, SemiB, BetaB);

        std::cout << "------------------- HASIL ------------------------------";

        if (ElectronicsA.getSemiconductor() == ElectronicsB.getSemiconductor()){
            std::cout << "\nData Pertama: ";
            ElectronicsA.Data();
            std::cout << std::endl;
            std::cout << "Data Kedua: ";
            ElectronicsB.Data();
            std::cout << std::endl;
            Darlington(BetaA, BetaB);
        } else {
            std::cout << "\nData Pertama: ";
            ElectronicsA.Data();
            std::cout << std::endl;
            std::cout << "Data Kedua: ";
            ElectronicsB.Data();
            std::cout << std::endl;

        }

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "-------------------------------------------------";
    }
};

int main(){
    Jawaban jawaban = Jawaban();
    jawaban.NomorSatu();
    jawaban.NomorDua();
    jawaban.NomorTiga();
    return 0;
}
