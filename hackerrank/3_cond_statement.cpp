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

int main()
{
    std::string n_temp;
    std::getline(std::cin, n_temp);
    std::vector<std::string> num_str {
        "one", "two", "three",
        "four", "five", "six", "seven",
        "eight", "nine"
    };

    int n = stoi(ltrim(rtrim(n_temp)));


    // Write your code here
    try {
        std::cout << num_str.at(n-1);
    } catch (const std::out_of_range& e) {
        std::cout << "Greater than 9";
    }

    return 0;
}


