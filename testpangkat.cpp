#include <iostream>
using namespace std;

float power(int x, int y){
	float a = 1;
	for (int i=0; i < y; i++){
		a = a*x;
	}
	return a;
}

int main(){
	float x,y;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	cout << power(x,y) << endl;
	return 0;
}
