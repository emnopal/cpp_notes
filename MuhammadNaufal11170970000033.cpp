#include "std_lib_facilities.h"

class Date{
public:
    Date(int yy, int mm, int dd); //constructor
    void add_day(int n);
    void mult_month(int mm);

private:
    int y, m, d;
};

enum month{
    jan = 1, feb, mar, apr, mei, jun, jul, ags, sep, okt, nov, des
};

Date::Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} // check for valid date and initialize
{
    if ((m > des) || (m < jan)) // wrong input here
    {
        error("outrage input, month has only 12");
    }
    else if (d <= 0)
    {
        error("outrage input, day has no negative member. are you using time travel?");
    }
    else if (m == feb)
    {
        if (d >= 30)
        {
            error("in leap year february has only 29 days");
        }
    }
    else if ((m == apr) || (m == jun) || (m == sep) || (m == nov))
    {
        if (d >= 31)
        {
            error("day in these month has only 30 days");
        }
    }
    else if ((m == jan) || (m == mar) || (m == mei) || (m == jul) || (m == ags) || (m == okt) || (m == des))
    {
        if (d >= 32)
        {
            error("day in these month has only 31 days");
        }
    }
    else 
    {
        yy = y;
        mm = m;
        dd = d;
    }
    string cc = to_string(m);
    if (m == jan)
        cc = "January";
    if (m == feb)
        cc = "February";
    if (m == mar)
        cc = "March";
    if (m == apr)
        cc = "April";
    if (m == mei)
        cc = "May";
    if (m == jun)
        cc = "June";
    if (m == jul)
        cc = "July";
    if (m == ags)
        cc = "August";
    if (m == sep)
        cc = "September";
    if (m == okt)
        cc = "October";
    if (m == nov)
        cc = "November";
    if (m == des)
        cc = "December";
    cout << "Calendar : " << d << " " << cc << " " << y << endl;
}

month operator++(month &m) // prefix increment operator
{
    // “wrap around”:
    m = (m == month::des) ? month::jan : month(int(m) + 1);
    return m;
}

void Date::add_day(int n)
{

    if (n < 0)
        error("day is less than 0");
    int hasiltambah = d + n;
    if (m == 2)
    {
        if (hasiltambah > 29)
        {
            ++m;
            hasiltambah -= 29;
        }
    }
    if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))
    {
        if (hasiltambah > 31)
        {
            ++m;
            hasiltambah -= 31;
        }
    }
    if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
    {
        if (hasiltambah > 30)
        {
            ++m;
            hasiltambah -= 30;
        }
    }
    if (m > 12)
    {
        y++;
        m -= 12;
    }
    string cc = to_string(m);
    if (m == 1)
        cc = "January";
    if (m == 2)
        cc = "February";
    if (m == 3)
        cc = "March";
    if (m == 4)
        cc = "April";
    if (m == 5)
        cc = "May";
    if (m == 6)
        cc = "June";
    if (m == 7)
        cc = "July";
    if (m == 8)
        cc = "August";
    if (m == 9)
        cc = "September";
    if (m == 10)
        cc = "October";
    if (m == 11)
        cc = "November";
    if (m == 12)
        cc = "December";
    cout << "if you add " << n << " so the result is: " << hasiltambah << " " << cc << " " << y << endl;
}

int main()
{
    cout << "Muhammad Naufal\n";
    cout << "11170970000033\n";
    int hh, bb, tt;
    cout << "Input your Calendar  \n";
    cout << "Day: ";
    cin >> hh;
    cout << "Month: ";
    cin >> bb;
    cout << "Year: ";
    cin >> tt;
    Date kalender{tt, bb, hh};
    cout << "\nDo you want to add the calendar? ";
    int tambah;
    cin >> tambah;
    kalender.add_day(tambah);
    return 0;
}