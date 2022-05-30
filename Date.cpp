#include "std_lib_facilities.h"

struct Reading {
    int d,m,y;
};

class Date{
public:
    Date(int dd,int mm, int yy){d=dd; m = mm, y = yy;};
    friend ostream& operator<<(ostream& os, const Date& dd);
    void init_day(int yy, int mm, int dd);
    //void add_day(int n);
private:
    int y,m,d;
};

istream& operator>>(istream& is, Date& dd){
    // Read date in format: ( year , month , day )
    int d, m, y;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> d >> ch2 >> m >> ch3 >> y >> ch4;
    if (!is) return is; // we didn’t get our values, so just leave
    if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')') { // oops: format error
        is.clear(ios_base::failbit);       // something wrong: set state to fail()
        return is;         // and leave
    }
    dd = Date{d,m,y};   // update dd
    return is;          // and leave with is in the good() state
}

ostream& operator<<(ostream& os, const Date& dd){
    os <<dd.d<<" "<< dd.m<<" "<< dd.y;
    return os;
};

enum month {jan=1, feb, mar, apr, mei, jun, jul, ags, sep, okt, nov, des};

void Date::init_day(int yy, int mm, int dd){// check for valid date and initialize
    if ((m > des) || (m<jan)){     // wrong statement
        error("out of range, month range is from 1 - 12");
    }
    else if (d<=0){
        error("out of range, day range is from 1 - 31");
    }
    else if (m==feb){
        if (d>=30){
            error("out of range, month range in leap February is from 1 - 29");
        }
    }
    else if ((m==apr) || (m==jun) || (m==sep) || (m==nov)){
        if (d>=31){
            error("out of range, day range is from 1 - 30");
        }
    }
    else if ((m==jan) || (m==mar) || (m==mei) || (m==jul) || (m==ags) || (m==okt) || (m==des)){
        if (d>=32){
            error("out of range, day range is from 1 - 31");
        }
    }
    else{   //true statement
        yy = y;
        mm = m;
        dd = d;
    }
}

month operator++(month& m){  // prefix increment operator
    // “wrap around”:
    m = (m==month::des) ? month::jan : month(int(m)+1); 
    return m;
}


int main(){
    cout << "-----------------------------------\n";
    cout << "Calendar Checker Using *.txt File\n";
    cout << "Created by Muhammad Naufal\n";
    cout << "11170970000033\n";
    cout << "Instrumentation Programming\n";
    cout << "-----------------------------------\n";
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist {iname};   // ifstream is an“input stream from a file”
                // defining an ifstream with a name string
                // opens the file of that name for reading
    if (!ist) error("can’t open input file ", iname);
    vector<Reading> temps;
    int d,m,y;
    while (ist >> d >> m >> y ) {
        temps.push_back( Reading{d,m,y} );
    }
/*    Reading cetak;
    for (size_t i = 0; i < temps.size(); i++)
    {
        cetak = temps[i];
        cout << cetak.d  << " " << cetak.m  << " " << cetak.y << endl;
    }*/ // this code is distrubing
    int hh,bb,tt;
    vector <Date> tmp;
    Date tanggal{tt,bb,hh};
    cout << "Format: (dd,mm,yyyy)\n";
    cout << "Date Input: "; 
    while (cin >> tanggal) {
        tanggal.init_day(tt,bb,hh);
        tmp.push_back(tanggal);
        cout << "true format!, type again to continue, CTRL+C to close\n";
    }
    return 0;
}