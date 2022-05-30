#include <iostream>
#include <string.h>
using namespace std;

class Resistor{ 
private: 
	float Resistantion;
	float Pararels;
	string Units;
public: 
    Resistor(float Resistansi, string Satuan){ 
    	Resistantion = Resistansi;
    	Units = Satuan;
    }
	void tampilkan(){
		cout << "Nilai Resistansinya adalah: " << Resistantion << " " << Units << endl;
	}
	void setResistantion(float NewResistantion){
		Resistantion = NewResistantion;
	}
	void setUnits(string NewUnits){
		Units = NewUnits;
	}
	float getResistantion(){
		return Resistantion;
	}
	string getUnits(){
		return Units;
	}
	Resistor Paralel(Resistor Res1, Resistor Res2){ // Member Function dari Darlington
    	//Resistor::Paralels;
        if (Res1.getUnits() == Res2.getUnits()){
			Pararels = Res1.getResistantion() * Res2.getResistantion() / (Res1.getResistantion() + Res2.getResistantion());
			cout << "Resistor Paralel nya: " << Pararels;
        }
        else{
            cout << "Satuan tidak sama"; 
            return *this;
        }
    }

};

int main(){
	float resis,resist;
	string satuan;
	// resistor 1
	float resis1,resist1;
	string satuan1;
	cout << "nilai resistor 1: ";
	cin >> resis1;
	if (resis1 <= 1000){
		satuan1 = "Ohm";
	}
	if (resis1 >= 1000){
		resis1 = resis1/1000;
		satuan1 = "kOhm";
	}
	if (resis1 >= 1000000){
		resis1 = resis1/1000000;
		satuan1 = "MOhm";
	}
	// resistor 2
	float resis2,resist2;
	string satuan2;
	cout << "nilai resistor 2: ";
	cin >> resis2;
	if (resis2 <= 1000){
		satuan2 = "Ohm";
	}
	if (resis2 >= 1000){
		resis2 = resis2/1000;
		satuan2 = "kOhm";
	}
	if (resis2 >= 1000000){
		resis2 = resis2/1000000;
		satuan2 = "MOhm";
	}
	Resistor ResistorA = Resistor(resis1, satuan1);
	Resistor ResistorB = Resistor(resis2, satuan2);
	Resistor Hitung = Resistor(resis, satuan);
	ResistorA.tampilkan();
	ResistorB.tampilkan();
	Hitung.Paralel(ResistorA, ResistorB);
	return 0;
}