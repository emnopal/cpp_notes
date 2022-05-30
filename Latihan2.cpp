#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;

double pows(float number, int power){
    int p = 1;
    for (int i = 0; i <= power; i++){
        p = p * number;
    }
    return p;
}

float pi(int iteration){
    float pie = 0;
    for (int i = 0; i < iteration; i++){
        pie = pie + (-4 * pows(-1, i) / (2*i + 1));
    }
    return pie;
}

int main(){
    cout << setprecision(7) << pi(20000);
    return 0;
}
