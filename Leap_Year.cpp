#include <iostream>

bool oldLeapYear(int year){
    if (year % 4 == 0){
        return true;
        if (year % 100 == 0){
            return true;
            if (year % 400 == 0){
                return true;
            }
        }
    }
    return false;
};

bool leapYear(unsigned int year){
    return year % 4 == 0 ? true : (
        year % 100 == 0 ? true : (
            year % 400 == 0 ? true : false
        )
    );
}

std::string parseLeapYear(unsigned int year){
    return leapYear(year) ? "Leap year!" : "Not a leap year!";
};


int main(){
    int year;
    std::cout << "enter a year: ";
    std::cin >> year;
    std::cout << parseLeapYear(year);
    return 0;
}
