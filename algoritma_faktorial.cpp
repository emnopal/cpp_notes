#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double fact;
	double factorial = 1;
	cout << "factorial: ";
	cin >> fact;
	for (int i = 1; i <= fact; i++){
		factorial = factorial*i;
	}
	cout << setprecision(10) << factorial;
	return 0;
}