#include <iostream>

int main(){
    int i, a[32], n, temp;
    std::cout;
    std::cin >> n;
    std::cout;
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] > a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                break;
            }
        }
    }
    std::cout << temp;
    return 0;
}