#include <iostream>
using std::cin;
using std::cout;
//#include "error"

void urut(int *q, int length){
  int m,t;
    for(m=0;m<length;m++){
      for(t=0;t<m;t++){
        if(q[m]<q[t]){
          int temp=q[m]; //swap 
          q[m]=q[t];
          q[t]=temp;
        }
      }
    }
};

void cetak(int *p, int length){
    int i=0;
    for(i=0;i<length;i++){
      cout<<p[i]<<" ";
    }
};

int main(){
  int n=1000;
  int a;
  int i=0;
  int *integers=new int [n];
  cout << "Jumlah Kasus: ";
  cin >> a;
  for (int j = 0; j < a; j++){
    cout << "Angka yang ingin diurutkan: \n";
    cin >> n;
    cout << "Masukkan angkanya: \n";
    for (int i = 0; i < n; i++){
      cin >> integers[i];
    }
      urut(integers,n);
      cetak(integers,n);
      cout << "\n";
  }
  return 0;   
}
