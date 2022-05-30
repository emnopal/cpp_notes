#include <iostream>
#include <algorithm>
using namespace std;
#define size 1000

int main(){
  int data,lots[size],things,rows,aa[size],bb[size],cc[size],dd[size],ee[size],ff[size];

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

    cout << "\nsetelah dirapihkan: \n";
    copy( lots, lots + N, aa );
    for_each( aa, aa + N, []( int x ){});
    //cout << endl;
    copy( lots + N, lots + 2 * N, bb );
    for_each( bb, bb + N, []( int x ){});  
    //cout << endl;
    copy( lots + N * 2, lots + 3 * N, cc );
    for_each( cc, cc + N, []( int x ){}); 
    //cout << endl;
    copy( lots + N * 3, lots + 4 * N, dd );
    for_each( dd, dd + N, []( int x ){});    
    //cout << endl;     
    copy( lots + N * 4, lots + 5 * N, ee );
    for_each( ee, ee + N, []( int x ){}); 
    //cout << endl;
    copy( lots + N * 5, lots + 6 * N, ff );
    for_each( ff, ff + N, []( int x ){});
    //cout << endl;
    for (size_t i=0; i < N; i++ ){
      cout << aa[i] << " " << bb[i] << " " << cc[i] << " " << dd[i] << " " << ee[i] << " " << ff[i] << "\n";
    }

  } 
  return 0;
}