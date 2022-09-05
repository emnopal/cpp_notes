#include <bits/stdc++.h>

std::string ltrim(const std::string &str) {
    std::string s(str);

    s.erase(
        s.begin(),
        std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(isspace)))
    );

    return s;
}

std::string rtrim(const std::string &str) {
    std::string s(str);

    s.erase(
        std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

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
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    std::string n_temp_init, n_temp_end;
    std::getline(std::cin, n_temp_init);
    std::getline(std::cin, n_temp_end);

    int n_init = stoi(ltrim(rtrim(n_temp_init)));
    int n_end = stoi(ltrim(rtrim(n_temp_end)));

    for (int i = n_init; i <= n_end; i++){
        if (i < 10){
            std::cout << ifNumLessThan9DoThis(i) << "\n";
        } else {
            std::cout << isOddOrEven(i) << "\n";
        }
    }

    return 0;
}
