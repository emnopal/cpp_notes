#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double n, fibonacci = 0,a, n1 = 1, n2 = 2;
	cout << "Deret Fibonacci ke: ";
	cin >> n;
	cout << fibonacci << " " << n1 << " " << n1 
	<< " " << n2 << " ";
	for (int i = 3; i < n; i++){
		fibonacci = n1+n2;
		n1 = n2;
		n2 = fibonacci;
		cout << setprecision(64) << fibonacci << "\n";
	}
	return 0;
}