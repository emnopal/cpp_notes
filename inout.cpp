#include "std_lib_facilities.h"

struct Reading{
    int hour;
    double temperature;
};

int main(){
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist{iname};
    if (!ist)
        error("can't open input file", iname);
    vector<Reading> temps;
    int hour;
    double temperature;
    while (ist >> hour >> temperature){
        if (hour < 0 || 23 < hour)
            error("hour out of range");
        if (temperature < 0 || 10 < temperature)
            error("temperature out of range");
        temps.push_back(Reading{hour,temperature});
    }
    Reading print;
    for (int i = 0; i < temps.size();i++){
        print = temps[i];
        cout << print.hour << " " << print.temperature << endl;
    }
return 0;
}