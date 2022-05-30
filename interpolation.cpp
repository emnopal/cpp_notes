#include <iostream>
using namespace std;

struct Data{
    double x, y;
};

double interpolate(Data f[], double xi, int n){
    double result = 0;
    for (int i = 0; i < n; i++){
        double term = f[i].y;
        for (int j = 0; j < n; j++){
            if (j != i)
                term = term * (xi - f[j].x) / double(f[i].x - f[j].x);
        }
        result += term;
    }
    return result;
}

int main(){
    Data f[] = {{0, 1}, {1.525, 0.8617}, {3.050, 0.7385}, {4.575, 0.6292}, {6.10, 0.5328}, {7.625, 0.4481}, {9.150, 0.371}};
    cout << interpolate(f, 1.76, 2);
    return 0;
}
