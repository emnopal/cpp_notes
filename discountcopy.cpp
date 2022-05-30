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

#include <iostream>
using std::cout;
using std::cin;

int main(){
    int shop, amount[1000], colour[1000][1000],i,j,K;
    char size[10][10];
    int discount = 0;
    cout << "Enter your case: ";
    cin >> shop;
    for (int i = 1; i <= shop; i++){
        cout << "Enter your friend: ";
        cin >> amount[i];
            for (int j = 1; j <= amount[i]; j++){
                cin >> size[i][j]; 
                cin >> colour[i][j];
            }
    }

    for (int k = 0; k <= shop; k++){
        for (int i = 1; i <= amount[k]; i++){
            for (int j = i+1; j <= amount[k]; j++){
                if ((size[k][i] == size[k][j]) && (colour[k][i] == colour[k][j])){
                    discount = discount+10;
                    }
                }
            }
    cout << "Discount: " << discount << "\n";
    }
return 0;
}
