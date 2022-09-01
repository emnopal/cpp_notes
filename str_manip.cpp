#include <iostream>

std::string toLower(std::string str){
    std::string lowerStr;
    for(char& char_str: str){
        lowerStr.push_back(char_str + 32);
    }
    return lowerStr;
};

std::string toUpper(std::string str){
    std::string upperStr;
    for(char& char_str: str){
        upperStr.push_back(char_str - 32);
    }
    return upperStr;
};

std::string toTitle(std::string str){
    std::string titleStr;
    for(int i = 0; i < str.length(); i++){
        if(i==0){
            titleStr.push_back(str[i] + 32);
        } else {
            titleStr.push_back(str[i]);
        }
    }
    return titleStr;
}

int main(){

    std::string test = "PHP";
    std::string testResult = toLower(test);
    std::cout << testResult;
    std::cout << std::endl;

    std::string test0 = "php";
    std::string testResult0 = toUpper(test0);
    std::cout << testResult0;
    std::cout << std::endl;

    std::string test1 = "php";
    std::string testResult1 = toTitle(test1);
    std::cout << testResult1;
    std::cout << std::endl;

    return 0;
}
