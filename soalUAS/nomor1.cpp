#include <iostream>
using namespace std;

int main(){
	int n, i, m=0, flag=0;
	cout << "Masukkan angka untuk dicek apakah bilangan prima: ";
	cin >> n;
	m = n / 2;
	for (i = 2;i<=m;i++) {
		if (n % i == 0) {
			cout << "Bukan bilangan prima." << endl;
			flag=1;
			break;
		}
	}
	if (flag==0)
	cout << "Bilngan prima." << endl;
	return 0;
}