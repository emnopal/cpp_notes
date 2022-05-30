#include <iostream>
using namespace std;

/* Function */
float idrtousd(float amount){
	return amount / 14242.26;
}

float usdtoidr(float amount){
	return amount * 14242.26;
}

/* Main Program */
int main(){
	/* Variable */
	int x;
	float amount;
	cout << "1. US Dollar to Indonesia Rupiah\n";
	cout << "2. Indonesia Rupiah to US Dollar\n";
	cout << "Choose a Currency: ";
	cin >> x;

	if( x == 1){
	cout << "US Dollar to Indonesia Rupiah\n";
	cout << "Enter a Value: ";
	cin >> amount;
	cout << "Result: " << usdtoidr(amount) << endl;
	}

	if(x == 2){
	cout << "Indonesia Rupiah to US Dollar\n";
	cout << "Enter a Value: ";
	cin >> amount;
	cout << "Result: " << idrtousd(amount) << endl;
	}
	
return 0;
}
