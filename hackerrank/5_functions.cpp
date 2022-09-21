#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int max_vect(std::vector<int> &vec_nums) {
    std::sort(vec_nums.begin(), vec_nums.end(), std::greater<int>());
    return vec_nums.at(0);
}


int main() {

    int a,b,c,d;

    std::cin >> a >> b >> c >> d;
    std::vector<int> nums {a,b,c,d};

    std::cout << max_vect(nums);

    return 0;
}
