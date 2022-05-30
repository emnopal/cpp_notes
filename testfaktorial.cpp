#include <iostream>
using namespace std;

double factorial(int n){
	int a = 1;
	for (int i = 1; i <= n; i++){
		a = a*i;
	}
	return a;
}

int main(){
	int n;
	cout << "n: ";
	cin >> n;
	cout << factorial(n);
	return 0;
}
