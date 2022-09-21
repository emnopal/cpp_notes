#include <bits/stdc++.h>

std::string isOddOrEven(int num){
    return num%2 == 0 ? "even" : "odd";
}

std::string ifNumLessThan9DoThis(int num) {
    std::vector<std::string> num_str {
        "one", "two", "three",
        "four", "five", "six", "seven",
        "eight", "nine"
    };
    return num_str.at(num-1);
}

int main() {

    int n_init, n_end;

    std::cin >> n_init >> n_end;

    for (int i = n_init; i <= n_end; i++){
        if (i < 10){
            std::cout << ifNumLessThan9DoThis(i) << "\n";
        } else {
            std::cout << isOddOrEven(i) << "\n";
        }
    }

    return 0;
}
