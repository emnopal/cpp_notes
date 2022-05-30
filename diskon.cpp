#include "std_lib_facilities.h"

int main(){
    int shop, amount[10], colour[10][10],i,j,k;
    char size[10][10];
    int discount = 0;
    cout << "Enter your case: ";
    cin >> shop;
    for (int i = 0; i <= shop-1; i++){
        cout << "Enter your friend: ";
        cin >> amount[i];
            for (int j = 0; j <= amount[i]-1; j++){
                cin >> size[i][j]; 
                cin >> colour[i][j];
                if (size[i][j] != 'S'){
                    if (size[i][j] != 'M'){
                        if (size[i][j] != 'L'){
                            error("Please input S, M or L");
                        }
                    }
                }
                if (colour[i][j] < 1 || colour[i][j] > 1000){
                    error("Please input colour between 1 and 1000");
                }
                }
    }
    for (int k = 0; k <= shop-1; k++){    
        for (int i = 0; i <= amount[k]-1; i++){
            for (int j = i+1; j <= amount[k]-1; j++){
                if ((size[k][i] != '0') && (colour[k][i] != 0)){
                    if ((size[k][i] == size[k][j]) && (colour[k][i] == colour[k][j])){
                        discount = discount + 10;
                        size[k][i] = '0';
                        size[k][j] = '0';
                        colour[k][i] = 0;
                        colour[k][j] = 0;
                    }
                }
            }
        }    
        cout << "Discount: " << discount << "\n";
        discount = 0;
        }
return 0;
}
