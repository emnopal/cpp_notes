#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
#define isi 10

int main(){
	float baris, kolom, a[isi][isi], b[isi][isi], jumlah[isi][isi], kurang[isi][isi], kali[isi][isi];
	int operasi;

	cout << "Operasi Matriks: \n";
	cout << "1. Penjumlahan \n";
	cout << "2. Pengurangan \n";
	cout << "3. Perkalian \n";
	cin >> operasi;
	
	cout << "Masukkan Baris: ";
	cin >>  baris;
	kolom = baris;
	cout << "Masukkan Elemen Matriks Pertama: \n";
	
	for (int i = 0; i < baris; i++){
		for (int j = 0; j < kolom; j++){
			cin >> a[i][j];
			cout << a[i][j] << " ";
		}
	cout << endl;
	}
	
	cout << "Masukkan Elemen Matriks Kedua: \n";
	for (int i = 0; i < baris; i++){
		for (int j = 0; j < kolom; j++){
			cin >> b[i][j];
			cout << b[i][j] << " ";
		}
	cout << endl;
	}

	if (operasi == 1){
		cout << "Penjumlahan: \n";
		for (int i = 0; i < baris; i++){
			for (int j = 0; j < kolom; j++){
				jumlah[i][j] = a[i][j]+b[i][j];
				cout << jumlah[i][j] << " ";
			}
		cout << endl;
		}
	}

	if (operasi == 2){
		cout << "Pengurangan: \n";
		for (int i = 0; i < baris; i++){
			for (int j = 0; j < kolom; j++){
				kurang[i][j] = a[i][j]-b[i][j];
				cout << kurang[i][j] << " ";
			}
		cout << endl;
		}
	}

	if (operasi == 3){
		cout << "Perkalian: \n";
		for (int i = 0; i < baris; i++){
			for (int j = 0; j < kolom; j++){
				for (int k = 0; k < baris; k++){
					kali[i][j] = kali[i][j] + a[i][j] * b[j][k];
				}
			cout << kali[i][j] << " ";
			}
		cout << endl;
		}
	}
return 0;
}
