#include <iostream>
#include <string.h>
#include <stdexcept>

class Resistor
{
private:
	float Resistantion;
	float Pararels;
	std::string Units;

public:
	Resistor(float &Resistantion, std::string &Units){
		this->Resistantion = Resistantion;
		this->Units = Units;
	}

	void tampilkan(){
		std::cout << "Nilai Resistansinya adalah: " <<
		this->Resistantion << " " <<
		this->Units << std::endl;
	}

	void setResistantion(float &Resistantion){
		this->Resistantion = Resistantion;
	}

	void setUnits(std::string &Units){
		this->Units = Units;
	}

	float getResistantion(){
		return this->Resistantion;
	}

	std::string getUnits(){
		return this->Units;
	}

	// Paralel as method of class Resistor
	/*
	Make resistor Paralel
	*/
	std::pair<float, std::string> Paralel(Resistor AnotherResistor){
		if (this->getUnits() == AnotherResistor.getUnits()){

			Pararels = this->getResistantion() * AnotherResistor.getResistantion() /
				(this->getResistantion() + AnotherResistor.getResistantion());

			return std::make_pair(Pararels, this->getUnits());
		} else {
			throw std::invalid_argument("Satuan tidak sama");
		}
	};

};

// Paralel as independent function
// std::pair<float, std::string> Paralel(Resistor ResistorA, Resistor ResistorB){
// 	float Pararels;
// 	if (ResistorA.getUnits() == ResistorB.getUnits()){
// 		Pararels = ResistorA.getResistantion() * ResistorB.getResistantion() /
// 		 (ResistorA.getResistantion() + ResistorB.getResistantion());
// 		return std::make_pair(Pararels, ResistorA.getUnits());
// 	} else {
// 		throw std::invalid_argument("Satuan tidak sama");
// 	}
// };

std::string GetSatuan(float satuan)
{
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
	ResistorA.tampilkan();

	Resistor ResistorB = Resistor(resistor1, satuan1);
	ResistorB.tampilkan();

	// if we are using Paralel as independent function
	// std::pair<float, std::string> resistorFinal = Paralel(ResistorA, ResistorB);

	// if we are using Paralel as method of class Resistor
	std::pair<float, std::string> resistorFinal = ResistorA.Paralel(ResistorB);

	std::cout << "Resistor Paralel nya: " << resistorFinal.first << " " << resistorFinal.second;

	return 0;
}
