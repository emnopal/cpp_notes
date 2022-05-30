#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.14159265

int main(){
    double Theta,coss;
    cout << "Theta: ";
    cin >> Theta;
    coss = cos(Theta*PI/180);
    cout << coss;
    return 0;
}