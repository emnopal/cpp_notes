#include "std_lib_facilities.h"
#include <iostream>
using namespace std;

namespace Chrono{
class Date{
public:
	enum Month{
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};
	class Invalid{}; // to throw as exception
	Date(int d, Month m, int y);
	Date();
	//non-modifying operations
	int day() const{ return d; }
	Month month() const { return m; }
	int year() const { return y; }
	//modifying operations
private:
	int d,y;
	Month m;
};

ostream &operator<<(ostream &os, const Date &b);
istream &operator>>(istream &is, Date &dd);

//const Date &default_date();
}

namespace Chrono{
Date::Date(int dd, Month mm, int yy)
	:y{yy}, m{mm}, d{dd}{
	if (d <= 0){ //if day is less than 0
		error("wrong input, range of day is 1 - 31");
	}
	//else{
	//	cout << "The Calendar is: " << dd << " " << " " << mm << " " << yy << endl;
	//}

}

namespace Chrono{
int main(){
    int yy,dd,Month;// mm;
    cout << "Enter your Calendar!\n";
    cout << "Date: ";
    cin >> dd;
    cout << "Month: ";
    cin >> Month;
    cout << "Year: ";
    cin >> yy;
    cout << "\n";
	Date();
	return 0;
}
}
}
