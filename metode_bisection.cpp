#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/* Fungsi */
/* Ganti fungsi aja kalo mau nyari fungsi lain */
double f(double x) {
	return 2 * pow(x, 4) + 4 * pow(x, 3) - 3 * pow(x, 2) - x + cos(x) + 11;
}

/* Fungsi Turunan */
/* Jangan lupa turunin dulu lah */
double df(double x) {
	return 8 * pow(x, 3) + 12 * pow(x, 2) - 6 * x - 1 + sin(x);
}

/* Programnya */
int main() {
	double x, x1, e, fx, fx1;
	cout.precision(4);
	cout.setf(ios::fixed);
	cout << "Masukkan Tebakan Awal: \n";
	cin >> x1;
	cout << "Keakuratan: \n";
	cin >> e;
	do {
		x = x1;
		fx = f(x);
		fx1 = df(x);
		x1 = x - (fx / fx1);
		cout << x << " " << x1 << " " << abs(x1 - x) << endl;
	} while (fabs(x1 - x) <= e);
	cout << "Akar-akarnya adalah: \n" << x1 << endl;
	return 0;
}