#include "calendar.h"

void checkyourcalendar(calendar& dd, int d, int m, int y){
    if ((m > 12) || (m <= 0)){ //wrong month input
        error("wrong input, range of month is 1 - 12");
    }
    else if (d <= 0){ //if day is less than 0
        error("wrong input, range of day is 1 -31");
    }
    else if (m == 2){ //in February
        if (d>=30){ //leap year
            if (y%400==0) error("wrong input, day in the february at leap year range is 1 - 29");
            if ((y%400!=0)&&(y%100!=0)){
                if (y%4!=0) error("wrong input, day in the february at leap year range is 1 - 29");
            }
        }
        if (d>=29){ //not leap year
            if ((y%400!=0)&&(y%100==0)) error("wrong input, day in the february at leap year range is 1 - 29");
            if ((y%400!=0)&&(y%100!=0)){
                if (y%4!=0) error("wrong input, day in the february at leap year range is 1 - 29");
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
    else{
        dd.y = y;
        dd.m = m;
        dd.d = d;
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
    cout << "calendar\t: " << d << " " << cc << " " << y << endl;
};