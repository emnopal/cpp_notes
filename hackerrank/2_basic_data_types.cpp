#include <bits/stdc++.h>

int main() {

    char *char_tmpll, *char_tmpld;
    std::string str, str_tmp;
    long long char_ll;
    long double char_ld;
    std::vector<std::string> words;

    std::getline(std::cin, str); // avoid whitespace while std::cin
    std::stringstream ss(str);

    while (std::getline(ss, str_tmp, ' ')) {
        words.push_back(str_tmp);
    }

    for (auto &word: words){

        char_ll = strtoll(word.c_str(), &char_tmpll, 10);
        char_ld = strtod(word.c_str(), &char_tmpld);

        if (!*char_tmpll){
            std::cout << std::setprecision(7) << char_ll << '\n';
            std::cout << std::fixed;
        } else if (!*char_tmpld) {
            std::cout << std::setprecision(7) << char_ld << '\n';
            std::cout << std::fixed;
        } else {
            std::cout << word << '\n';
        }
    }

    return 0;
}
