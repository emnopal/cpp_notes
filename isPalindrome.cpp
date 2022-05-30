#include <iostream>
#include <string>

std::string isPalindrome(std::string x){
    std::string reverseS;
    for (int i = x.size() - 1; i >= 0; i--){
        reverseS.push_back(x[i]);
    }
    return x == reverseS ? "true" : "false";
};

int main(){
    std::cout << "1. Problem 1: Palindrome" << std::endl;
    int S = 121;
    std::string S_str = std::to_string(S);
    std::cout << "is " << S << " Palindrome?: " <<isPalindrome(S_str);
    return 0;
};