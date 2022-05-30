#include <iostream>
using namespace std;

float power(float a, float b){
    int power = 1;
    for (int i = 1; i < b; i++){
        power = power * a;
    }
    return power;
}
