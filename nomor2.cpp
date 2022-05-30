#include <iostream>
#include <iomanip>
using namespace std;

int factorial(int n){
	if (n > 1)
		return n*factorial(n - 1);
	else
		return 1;
}

int power(float x ,int y) {
	int ans;
	for (int i=0; i<y; i++)
		ans *= x;
	return ans;
}

int cos(float x, int k){
	float cosx = 0;
	for (int i = 0; i <= k; i++)
		cosx = cosx + power(-1, i)*power(x, 2*i)/factorial(2*i);
	return cosx;
}

int main(){
	float pi = 3.14;
	float x;
	int k;
	cout << "masukkan nilai x: ";
	cin >> x;
	float y = 180*x/pi;
	cout << "masukan ketelitian: ";
	cin >> k;
	cout << "nilainya adalah: " << setprecision(6) << cos(y,k);
	return 0;
}