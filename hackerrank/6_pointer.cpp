#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*

Array notes:

if specified size: (eg arr[0], arr[1])
dont need to pass pointer into function

int func(int arr[5]){...}

otherwise, you can pass pointer into function

int func(int *arr){...}

*/

int getA(int num[2]) {
    return num[0] + num[1];
}

int getB(int num[2]) {
    return abs(num[0] - num[1]);
}

// or

// int getA(int *num) {
//     return num[0] + num[1];
// }

// int getB(int *num) {
//     return abs(num[0] - num[1]);
// }

int main() {

    int a, b;
    std::cin >> a >> b;

    int concat_nums[2] = {a, b};

    std::cout << getA(concat_nums) << std::endl;
    std::cout << getB(concat_nums) << std::endl;

    return 0;
}
