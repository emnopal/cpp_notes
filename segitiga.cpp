#include <iostream>
using namespace std;

int main(){
    int n, a[25];
    cout;
    cin >> n;
    cout;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (a[i] < a[j]){
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            cout << a[i];
        }
        cout << "\n";
    }

    return 0;
}