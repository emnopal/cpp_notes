#include <iostream>
int main(){
	int sum = 0;
	for (int i = 0; i<4; i++){
		for (int j = i; j <= i; j++){
			sum += j;
			std::cout << sum << std::endl;
		}
	}
	std::cout << "\n" << sum;
	return 0;
}
