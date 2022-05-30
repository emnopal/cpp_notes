/*
                            Question
Jojo is on vacation and he wants to buy souvenirs for his friends. 
When he goes to clothing shop, the shop owner offers him a 10 dollar discount
for every pair of items with the same size and colour. He interested with
the offer and remembered what colour and size his friends want. 
How much discount cah he get 

                                Data
Sample Input 
3 (Amount of Case) 
Case 1. 10 (The friend that Jojo had) 
Clothes Data M 1, M 2, S 1, L 1, L 1, L 1, M 2, M 2, M 2, L 3
Case 2. 5 (The friend that Jojo had)
Clothes Data M 1, L 2, L 1, S 3, S 4
Case 3. 1 (The friend that Jojo had)
Clothes Data M 1
int t,n,c; // t: case, n: number of friend, c: colour
char s; // s: size
*/

#include "std_lib_facilities.h"

class Discount{
public: 
    Discount(int belanjaan ,int barang, int warna, char ukuran);
private:
    int t,c[1000][1000],n[1000];
    char s[10][10];
};

Discount::Discount(int belanjaan ,int barang, int warna, char ukuran): t{belanjaan}, n{barang}, c{warna}, s{ukuran}{  
    int i,j;
    int disc = 0;
    for(int i = 0; i <= belanjaan-1; i++){
        for(int j = i+1; j <= barang[i]-1; j++){
                if((ukuran[i][j] = ukuran[j][i]) && (warna[i][j] = warna[j][i])){
                    disc = disc+10;
                };
        };
    cout << "Discount: " << disc << "\n";
    };
};  

int main(){
    int shop, amount[1000], colour[1000][1000],i,j;
    char size[10][10];
    cout << "Enter your case: ";
    cin >> shop;
    for (int i = 0; i <= shop-1; i++){
        cout << "Enter your friend: ";
        cin >> amount[i];
            for (int j = 0; j <= amount[i]-1; j++){
                cin >> size[i][j];
                cin >> colour[i][j];
            };
    };
    Discount diskon{shop, amount[1000], colour[1000][1000], size[10][10]};
return 0;
}



