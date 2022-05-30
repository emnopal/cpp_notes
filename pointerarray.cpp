#include <iostream>
using namespace std;
// * menujukkan nilai yang ditunjukkan oleh suatu variabel
// contoh int *p = new int (n) jadi si p tanpa bintang menunjukkan alamat di memori
// kalo si *p menunjukkan nilai dari p tersebut

void sortnumber(int *q){
    int m,t;
    for (m = 0; m < 5; m++){
        for (t=0; t < m; t++){
            if (q[m] < q[t]){
                int temp = q[m]; //swap 
                q[m] = q[t];
                q[t] = temp;
            }
        }
    }
}

char sortcharacter(char *p){
    int m, t;
    for (m = 0; m < 5; m++){
        for (t = 0; t < m; t++){
            if (p[m] < p[t]){
                char temp = p[m]; //swap
                p[m] = p[t];
                p[t] = temp;
            }
        }
    }
}

char character(char *p){
    for (int i = 0; i < 5; i++){
        cout << p[i] << " ";
    }
}

int number(int *q){
    for (int i = 0; i < 5; i++){
        cout << q[i] << " ";
    }
}

int main(){
    char *characters = new char[5];
    int *numbers = new int[5];
    int i = 0;
    for (int i = 0; i < 5; i++){
        cin >> numbers[i];
    }
    for (int i = 0; i < 5; i++){
        cin >> characters[i];
    }
    cout << "\n";
    character(characters);
    sortcharacter(characters);
    cout << "\n";
    sortnumber(numbers);
    number(numbers);
}