#include <iostream>
#include <string>
using namespace std;

//Create a struct for calendar
// d is for day, m is for month and y is for year
struct calendar{
    int d,m,y;
};

//if error occured
struct range_error : out_of_range{
    int index;
    range_error(int i): out_of_range("Range Error: " +to_string(i)), index(i) { }
};

//exit code
struct exit : runtime_error{
    exit() : runtime_error("Exit") {}
};

inline void error(const string& s){
    throw runtime_error(s);
};