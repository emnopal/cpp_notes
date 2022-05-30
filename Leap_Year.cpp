#include <iostream>

int leap_year(int year){
    if (year % 4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0)
                std::cout << year << " is a leap year!";
            else
                std::cout << year << " is not a leap year!";
        }
        else
            std::cout << year << " is a leap year!";
    }
    else
        std::cout << year << " is not a leap year!";
}


int main(){
    int year;
    std::cout << "enter a year: ";
    std::cin >> year;
    std::cout << leap_year(year);
    return 0;
}
