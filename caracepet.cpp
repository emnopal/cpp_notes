#include <iostream>
#include <cmath>
#include "error"
using std::cout;
using std::cin;
#define size 50

int main(){
  int data,lots[size],things,columns,rows,j,a,k,tudaray[size][size];

  cout << "Jumlah Kasus: ";
  cin >> data;
  
  for (int i = 0; i < data; i++){
      cout << "\nkasus ke " << i+1 << "\n";
      cout << "angka yang ingin diurutkan: ";
      cin >> things;

      cout << "baris dan kolom yang ingin dirapihkan :";
      cin >> rows;
      columns = things/rows + 1;

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

      cout << "Setelah diurutkan: \n";
      for (int k = 0; k < things; k++){
         cout << lots[k] << " ";
      } 
      
      for (int j = 0; j < rows; j++){
         tudaray[j][0] = lots[j];
         for (int k = 0; k < columns; k++){
            int b = k+1;
            int pt = j + rows*b;
            if (pt >= things){
               tudaray[j][b] = -1;
               break;
            }
            tudaray[j][b] = lots[pt];
         }
      }

      cout << "\nsetelah dirapihkan: \n";
      for (int j = 0; j < rows; j++){
         for (int k = 0; k < columns; k++){
            if (tudaray[j][k] == -1) break;
            cout << tudaray[j][k] << " ";
         }
         cout << endl;
      }
      cout << endl;
   return 1;
  }
  return 0;
}