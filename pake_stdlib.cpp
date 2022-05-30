#include <iostream>
#include <algorithm>
using namespace std;
#define size 1000

int main(){
  int data,lots[size],things,rows,aa[size],aaa[size][size];

  cout << "Jumlah Kasus: ";
  cin >> data;
  
  for (int i = 0; i < data; i++){
    
    cout << "angka yang ingin diurutkan: ";
    cin >> things;

    cout << "baris dan kolom yang ingin dirapihkan :";
    cin >> rows;
    size_t N = rows;
    cout << "masukkan angkanya: ";
    for (int j = 0; j < things; j++){
      cin >> lots[j];
      int array[rows*N] = {lots[j]};
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

    cout << "setelah dirapihkan: \n";

    for (int j = 0; j < rows; j++){
	    copy( lots + N * J , lots + (1+j) * N, aa[j] );
	    for_each( aa[j], aa[j] + N, []( int x ){});
	    aaa[size][size] = aa[size];
	    for (size_t i=0; i < N; i++ ){
	      cout << aaa[i][j] << " " << "\n";
	    }
    }
  } 
  return 0;
}