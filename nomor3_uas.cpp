#include <iostream>
#include <string.h>
#include <stdexcept>

class Resistor
{
private:
	float Resistantion;
	std::string Units;

public:
	Resistor(float resistantion, std::string units){
		// name of constructor must not same with name of parameter constructor
		Resistantion = resistantion;
		Units = units;
		// name of constructor will spread over class member
	}

	void tampilkan(){
		std::cout << "Nilai Resistansinya adalah: " << Resistantion << " " << Units << std::endl;
	}

	void setResistantion(float Resistantion){
		Resistantion = Resistantion;
	}

	void setUnits(std::string Units){
		Units = Units;
	}

	float getResistantion(){
		return Resistantion;
	}

	std::string getUnits(){
		return Units;
	}
};

std::pair<float, std::string> Paralel(Resistor ResistorA, Resistor ResistorB){
	float Pararels;
	if (ResistorA.getUnits() == ResistorB.getUnits()){
		Pararels = ResistorA.getResistantion() * ResistorB.getResistantion() /\
		 (ResistorA.getResistantion() + ResistorB.getResistantion());
		return std::make_pair(Pararels, ResistorA.getUnits());
	} else {
		throw std::invalid_argument("Satuan tidak sama");
	}
};

std::string GetSatuan(float satuan){
	std::string satuan_valid;
	if (satuan <= 1000){
		satuan_valid = "Ohm";
	}
	if (satuan >= 1000){
		satuan = satuan / 1000;
		satuan_valid = "kOhm";
	}
	if (satuan >= 1000000){
		satuan = satuan / 1000000;
		satuan_valid = "MOhm";
	}
	return satuan_valid;
}

// c++ main() needs to return int
int main()
{
	float resistor0, resistor1;
	std::string satuan0, satuan1;

	resistor0 = 12;
	resistor1 = 14;

	satuan0 = GetSatuan(resistor0);
	satuan1 = GetSatuan(resistor1);

	Resistor ResistorA = Resistor(resistor0, satuan0);
	Resistor ResistorB = Resistor(resistor1, satuan1);

	std::pair<float, std::string> resistorFinal = Paralel(ResistorA, ResistorB);

	std::cout << "Resistor Paralel nya: " << resistorFinal.first << " " << resistorFinal.second;

	return 0;
}
