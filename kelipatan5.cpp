#include <iostream>
using namespace std;

int main(){
	int i,n, input, output;
	cout << "masukan input: ";
	cin >> input;
	cout << "1. ";
	for (int i = 0; i <= 15; i++){
		n = 125 + 5*i;
		cout << n << " ";
	}
	cout << "\n2. ";
	for (int i = 0; i <= input; i++){
		output = i++;
		cout << output << " ";
	}
cout << endl;
return 0;
}
