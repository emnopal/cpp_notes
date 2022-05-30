/*
    Counting Compton Effect using C++
    by Muhammad Naufal
*/

// Library and Header input
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <string.h>

// better using this than using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::scientific;
using std::string;

// some constant
#define c 299792458
#define h 6.62607015e-34
#define m 9.10938356e-31
#define PI 3.14159265

// this is result from compton_wavelength = h/m*c
#define compton_wavelengthM 0.00000000000242 // in meter
#define compton_wavelengthnM 0.00242 // in nano Meter
#define compton_wavelengthA 0.0242 // in Angstorm
 

// compton scattering function
double Compton_Scattering(double Theta, double Lambda, string Units){ 
    if (Units == "nM" || Units == "nm")
        return compton_wavelengthnM*(1-cos(Theta*PI/180)) + Lambda;
    if (Units == "A" || Units == "a")
        return compton_wavelengthA*(1-cos(Theta*PI/180)) + Lambda;
    if (Units == "M" || Units == "m")
        return compton_wavelengthM*(1-cos(Theta*PI/180)) + Lambda;
}

// option 1
int count(){
    double Lambda, Theta;
    string Units;
    cout << "Data: \n";
    cout << "Angle: ";
    cin >> Theta;
    cout << "Wavelength: ";
    cin >> Lambda >> Units;
    cout << "Result: ";
    if (Units == "nm" || Units == "nM" || Units == "a" || Units == "A" && Theta != 0 )
        cout << setprecision(10) << Compton_Scattering(Theta, Lambda, Units) << " " << Units;
    if (Units == "M" || Units == "m" && Theta != 0)
        cout << setprecision(40) << Compton_Scattering(Theta, Lambda, Units) << " " << Units;
    else
        cout << Compton_Scattering(Theta, Lambda, Units) << " " << Units;
    return 1;
}

// Main Program
int main(){   
    int n;
    cout << "Welcome to Compton Effect Program: \n";
    cout << "Select menu to Continue \n";
    cout << "1. Counting a Value of Compton Effect\n";
    cout << "2. Graph of Compton Effect\n";
    cout << "3. Explanation of Compton Effect\n";
    cout << "Input a Menu Here: ";
    cin >> n;
    if (n == 1)
        count();
    if (n == 2)
        return 2;
    if (n == 3)
        return 3;
    return 0;
}
