#include <iostream>
using namespace std;
#define size 1000

int main(){
	int data,lots[size],things,rows,columns;
	int row = 0;
	
	cout << "Jumlah Kasus: ";
	cin >> data;
	
	for (int i = 0; i < data; i++){
		
		cout << "angka yang ingin diurutkan: ";
		cin >> things;

		cout << "baris dan kolom yang ingin dirapihkan :";
		cin >> rows >> columns;
		//cin >> rows;
		//columns = rows;
		
		cout << "masukkan angkanya: ";
		for (int j = 0; j < things; j++){
			cin >> lots[j];
		}
		
		for (int c = 0; c < things; c++){
			for (int d = 0; d < c; d++){
				if (lots[c] < lots[d]){
					int sort =  lots[c];
					lots[c] = lots[d];
					lots[d] = sort;
				}
			}
		}

		cout << "Setelah diurutkan: ";
		for (int k = 0; k < things; k++){
			cout << lots[k] << " ";
		}
		
		cout << "\nSetelah dirapihkan: \n";	
		for (int column = 0; column < rows; column++){
			for (int row = 0; row < columns; row++)
				cout << lots[row*columns+column] << " ";
				cout << "\n";
		}

	}	

	return 0;
}