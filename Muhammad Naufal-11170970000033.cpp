/* #include "std_lib_facilities" <-- we dont use this because it will gives an error to string */
#include <iostream>
#include <string>
using namespace std;

//Create a class for calendar
// d is for day, m is for month and y is for year
struct calendar{
    int da,d,m,y;
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

void checkyourcalendar(calendar& dd, int da, int d, int m, int y){ //Check your Calendar
    if ((m > 12) || (m <= 0)){ //wrong month input
        error("wrong input, range of month is 1 - 12");
    }
    else if ((da > 7) || (da <= 0)){
        error("wrong input, range of day is 1 - 7");
    }
    else if (d <= 0){ //if day is less than 0
        error("wrong input, range of day is 1 - 31");
    }
    else if (m == 2){ //in February
        if (d>=30){ //leap year
            if (y%400==0) error("wrong input, day in the february at leap year range is 1 - 29");
            if ((y%400!=0)&&(y%100!=0)){
                if (y%4!=0) error("wrong input, day in the february at leap year range is 1 - 29");
            }
        }
        if (d>=29){ //not leap year
            if ((y%400!=0)&&(y%100==0)) error("wrong input, day in the february range is 1 - 28");
            if ((y%400!=0)&&(y%100!=0)){
                if (y%4!=0) error("wrong input, day in the february range is 1 - 28");
            }
        }
    }
    else if ((m==4)||(m==6)||(m==9)||(m==11)){ //for 30 days month
        if (d>=31){
            error("wrong input, day in these years is not great than 30");
        }
    }
    else if ((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12)){ //for 31 days month
        if (d>=32){
            error("wrong input, day in these years is not great than 31");
        }
    }
    else{ //if our statement is true
        dd.y = y;
        dd.m = m;
        dd.d = d;
        dd.da = da;
    }
    string cc = to_string(m); //to convert from integer input month to string month 
    if (m==1) cc = "January";
    if (m==2) cc = "February";
    if (m==3) cc = "March";
    if (m==4) cc = "April";
    if (m==5) cc = "May";
    if (m==6) cc = "June";
    if (m==7) cc = "July";
    if (m==8) cc = "August";
    if (m==9) cc = "September";
    if (m==10) cc = "October";
    if (m==11) cc = "November";
    if (m==12) cc = "December";
    string daa = to_string(da); //to convert from integer input day to string day
    if (da==1) daa = "Sunday";
    if (da==2) daa = "Monday";
    if (da==3) daa = "Tueday";
    if (da==4) daa = "Wednesday";
    if (da==5) daa = "Thursday";
    if (da==6) daa = "Friday";
    if (da==7) daa = "Saturday";
    cout << "The Calendar is: " << daa << " " << d << " " << cc << " " << y << endl;
};

void addyourcalendar(int da, int d, int m, int y){ //to add calendar day
    cout << "Enter a value: ";
    int add;
    cin >> add;
    if (add < 0) error("unexpected result, day is less than 0, are you using time travel?");
    int result = d + add;
    if (m==2){ //leap year
        if (result > 29){
            if(y%400==0){
                m++;
                result -= 29;
            }
            if((y%400!=0) && (y%100!=0)){
                if(y%4==0){
                    m++;
                    result -= 29;
                }
            }
        }
        if (result > 28){ //not leap year
            if ((y%400!=0) && (y%100==0)){
                m++;
                result -= 28;
            }
            if((y%400!=0) && (y%100!=0)){
                if(y%4!=0){
                    m++;
                    result -= 28;
                }
            }
        }
    }
    if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12)){
        if (result > 31){
            m++;
            result -= 31;
        }
    }
    if((m==4) || (m==6) || (m==9) || (m==11)){
        if(result > 30)
        {
            m++;
            result -= 30;
        }
    }
    if (m > 12){
        y++;
        m -= 12;
    }
    {
        if (add > 365) error("unexpected result, year is more than 365 days");
            if (m==2){
                if (result > 29){ //a leap year
                    if(y%400==0){
                        m++;
                        result -= 29;
                    }
                    if((y%400!=0) && (y%100!=0)){
                        if(y%4==0){
                            m++;
                            result -= 29;
                        }
                    }
                }
                if (result > 28){ //not a leap year
                    if ((y%400!=0) && (y%100==0)){
                        m++;
                        result -= 28;
                    }
                    if((y%400!=0) && (y%100!=0)){
                        if(y%4!=0){
                            m++;
                            result -= 28;
                        }
                    }
                }
            }
            if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12)){
                if (result > 31){
                    m++;
                    result -= 31;
                }
            }
            if((m==4) || (m==6) || (m==9) || (m==11)){
                if(result > 30){
                    m++;
                    result -= 30;
                }
            }
            if (m > 12){
                y++;
                m -= 12;
            }
            if (m==2){
                if (result > 29){
                    if(y%400==0){
                        m++;
                        result -= 29;
                    }
                    if((y%400!=0) && (y%100!=0)){
                        if(y%4==0){
                            m++;
                            result -= 29;
                        }
                    }
                }
                if (result > 28){
                    if ((y%400!=0) && (y%100==0)){
                        m++;
                        result -= 28;
                    }
                    if((y%400!=0) && (y%100!=0)){
                        if(y%4!=0){
                            m++;
                            result -= 28;
                        }
                    }
                }
            }
            if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12)){
                if (result > 31){
                    m++;
                    result -= 31;
                }
            }
            if((m==4) || (m==6) || (m==9) || (m==11)){
                if(result > 30){
                    m++;
                    result -= 30;
                }
            }
            if (m > 12)
            {
                y++;
                m -= 12;
            }
            if (m==2){
                if (result > 29){
                    if(y%400==0){
                        m++;
                        result -= 29;
                    }
                    if((y%400!=0) && (y%100!=0)){
                        if(y%4==0){
                            m++;
                            result -= 29;
                        }
                    }
                }
                if (result > 28){
                    if ((y%400!=0) && (y%100==0)){
                        m++;
                        result -= 28;
                    }
                    if((y%400!=0) && (y%100!=0)){
                        if(y%4!=0){
                            m++;
                            result -= 28;
                        }
                    }
                }
            }
            if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12)){
                if (result > 31)
                {
                    m++;
                    result -= 31;
                }
            }
            if((m==4) || (m==6) || (m==9) || (m==11)){
                if(result > 30){
                    m++;
                    result -= 30;
                }
            }
            if (m > 12){
                y++;
                m -= 12;
            }
            if (m==2){
                if (result > 29){
                    if(y%400==0){
                        m++;
                        result -= 29;
                    }
                    if((y%400!=0) && (y%100!=0)){
                        if(y%4==0){
                            m++;
                            result -= 29;
                        }
                    }
                }
                if (result > 28){
                    if ((y%400!=0) && (y%100==0)){
                        m++;
                        result -= 28;
                    }
                    if((y%400!=0) && (y%100!=0)){
                        if(y%4!=0){
                            m++;
                            result -= 28;
                        }
                    }
                }
            }
            if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12)){
                if (result > 31){
                    m++;
                    result -= 31;
                }
            }
            if((m==4) || (m==6) || (m==9) || (m==11)){
                if(result > 30){
                    m++;
                    result -= 30;
                }
            }
            if (m > 12){
                y++;
                m -= 12;
            }
            if (m==2){
                if (result > 29){
                    if(y%400==0){
                        m++;
                        result -= 29;
                    }
                    if((y%400!=0) && (y%100!=0)){
                        if(y%4==0){
                            m++;
                            result -= 29;
                        }
                    }
                }
                if (result > 28){
                    if ((y%400!=0) && (y%100==0)){
                        m++;
                        result -= 28;
                    }
                    if((y%400!=0) && (y%100!=0)){
                        if(y%4!=0){
                            m++;
                            result -= 28;
                        }
                    }
                }
            }
            if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12)){
                if (result > 31){
                    m++;
                    result -= 31;
                }
            }
            if((m==4) || (m==6) || (m==9) || (m==11)){
                if(result > 30){
                    m++;
                    result -= 30;
                }
            }
            if (m > 12){
                y++;
                m -= 12;
            }
            if (m==2){
                if (result > 29){
                    if(y%400==0){
                        m++;
                        result -= 29;
                    }
                    if((y%400!=0) && (y%100!=0)){
                        if(y%4==0){
                            m++;
                            result -= 29;
                        }
                    }
                }
                if (result > 28){
                    if ((y%400!=0) && (y%100==0)){
                        m++;
                        result -= 28;
                    }
                    if((y%400!=0) && (y%100!=0)){
                        if(y%4!=0){
                            m++;
                            result -= 28;
                        }
                    }
                }
            }
            if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12)){
                if (result > 31){
                    m++;
                    result -= 31;
                }
            }
            if((m==4) || (m==6) || (m==9) || (m==11)){
                if(result > 30)
                {
                    m++;
                    result -= 30;
                }
            }
            if (m > 12){
                y++;
                m -= 12;
            }
    }
    string cc = to_string(m);
    if (m==1) cc = "January";
    if (m==2) cc = "February";
    if (m==3) cc = "March";
    if (m==4) cc = "April";
    if (m==5) cc = "May";
    if (m==6) cc = "June";
    if (m==7) cc = "July";
    if (m==8) cc = "August";
    if (m==9) cc = "September";
    if (m==10) cc = "October";
    if (m==11) cc = "November";
    if (m==12) cc = "December";
    string daa = to_string(da);
    if (da==1) daa = "Sunday";
    if (da==2) daa = "Monday";
    if (da==3) daa = "Tueday";
    if (da==4) daa = "Wednesday";
    if (da==5) daa = "Thursday";
    if (da==6) daa = "Friday";
    if (da==7) daa = "Saturday";
    cout << "if you add " << add << " so, the result is: " << daa << " " << result << " " << cc << " " << y << endl;
};

int Calendar(){
    calendar cldr;
    int yy,mm,dd,ddaa;
    char b;
    cout << "\n------------------------------------\n";
    cout << "Welcome to My Calendar App\n";
    cout << "Created by Muhammad Naufal\n";
    cout << "Student identity: 11170970000033\n";
    cout << "------------------------------------\n\n";
    cout << "Guide to use this calendar: \n";
    cout << "Day: 1-7, Date: 1-31 (depends on month), Month 1-12\n\n";
    cout << "Enter your Calendar!\n";
    cout << "Day: ";
    cin >> ddaa;
    cout << "Date: ";
    cin >> dd;
    cout << "Month: ";
    cin >> mm;
    cout << "Year: ";
    cin >> yy;
    cout << "do you want to add your calendar? ";
    cin >> b;
    cout << "\n";
    while (b == 'y' || b == 'Y'){
        checkyourcalendar(cldr,ddaa,dd,mm,yy);
        addyourcalendar(ddaa, dd, mm, yy);
    }
    while (b == 'n' || b == 'N'){
        checkyourcalendar(cldr,ddaa,dd,mm,yy);     
        return 0;       
    }
}

/*int main(){
    Calendar();
    char a;
    cout << "\nDo you want to run this program again? ";
    cin >> a;
    cout << "\n";
    while(a == 'y' || a == 'Y'){
        Calendar();
    }
    while(a == 'n' || a == 'N'){
        break;
    }
}*/

int main(){
    return Calendar();
}

