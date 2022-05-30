#include "std_lib_facilities.h"

struct Reading {
    int n,d,m,y;
};

class Date
{
    public:
    Date(int dd,int mm, int yy){d=dd; m = mm, y = yy;};
    friend ostream& operator<<(ostream& os, const Date& dd);
    void init_day(int yy, int mm, int dd);
    void add_day(int n);
    private:
    int y,m,d;
};

istream& operator>>(istream& is, Date& dd)
	// Read date in format: ( year , month , day )
{
	int d, m, y;
	char ch1, ch2, ch3, ch4;
	is >> ch1 >> d >> ch2 >> m >> ch3 >> y >> ch4;
	if (!is) return is;	// we didn’t get our values, so just leave
	if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')') {	// oops: format error
		is.clear(ios_base::failbit);	   // something wrong: set state to fail()
		return is;		   // and leave
	}
	dd = Date{d,m,y};	// update dd
	return is;			// and leave with is in the good() state
}

ostream& operator<<(ostream& os, const Date& dd)
{
    os <<dd.d<<" "<< dd.m<<" "<< dd.y;
    return os;
};

enum month {jan=1, feb, mar, apr, mei, jun, jul, ags, sep, okt, nov, des};

void Date::init_day(int yy, int mm, int dd)// check for valid date and initialize
{
    if ((m > des) || (m<jan))     // pernyataan salah disini
    {
        error("input bulan antara 1 ~ 12");
    }
    else if (d<=0)
    {
        error("input tanggal antara 1 ~ 31");
    }
    else if (m==feb)
    {
        if (d>=30)
        {
            error("tanggal pada bulan tersebut tidak lebih dari 29");
        }
    }
    else if ((m==apr) || (m==jun) || (m==sep) || (m==nov))
    {
        if (d>=31)
        {
            error("tanggal pada bulan tersebut tidak lebih dari 30");
        }
    }
    else if ((m==jan) || (m==mar) || (m==mei) || (m==jul) || (m==ags) || (m==okt) || (m==des))
    {
        if (d>=32)
        {
            error("tanggal pada bulan tersebut tidak lebih dari 31");
        }
    }
    else   //pernyataan benar
    {
        yy = y;
        mm = m;
        dd = d;
    }
}

month operator++(month& m)	// prefix increment operator
{
	// “wrap around”:
	m = (m==month::des) ? month::jan : month(int(m)+1); 
	return m;
}

void Date::add_day(int n)
{

    if (n < 0) error("tidak dapat mengurangi hari");
    int hasiltambah = d + n;
    if (m==feb)
    {
        if (hasiltambah > 29)
        {
            ++m;
            hasiltambah -= 29;
        }
    }
    if ((m==jan) || (m==mar) || (m==mei) || (m==jul) || (m==ags) || (m==okt) || (m==des))
    {
        if (hasiltambah > 31)
        {
            ++m;
            hasiltambah -= 31;
        }
    }
    if((m==apr) || (m==jun) || (m==sep) || (m==nov))
    {
        if(hasiltambah > 30)
        {
            ++m;
            hasiltambah -= 30;
        }
    }
    if (m > des)
    {
        y++;
        m -= 12;
    }
    string cc = to_string(m);
    if (m==1) cc = "Januari";
    if (m==2) cc = "Februari";
    if (m==3) cc = "Maret";
    if (m==4) cc = "April";
    if (m==5) cc = "Mei";
    if (m==6) cc = "Juni";
    if (m==7) cc = "Juli";
    if (m==8) cc = "Agustus";
    if (m==9) cc = "September";
    if (m==10) cc = "Oktober";
    if (m==11) cc = "November";
    if (m==12) cc = "Desember";
    cout << "tanggal lahir + " << n << "\t: "
    << hasiltambah << " " << cc << " " << y << endl;
}

int main()
{
    /////////////////////////////////ifstream///////////////////////////////////
    cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist {iname};	// ifstream is an“input stream from a file”
				// defining an ifstream with a name string
				// opens the file of that name for reading
	if (!ist) error("can’t open input file ", iname);
    /////////////////////////////membaca file txt//////////////////////////////
    vector<Reading> temps;
    int n,d,m,y;
	while (ist >> n >> d >> m >> y ) {
		if (n < 1 || 23 <n) error("number out of range");
		temps.push_back( Reading{n,d,m,y} );
	}
    //////////////////////////////output file txt//////////////////////////////
    Reading cetak;
    for (size_t i = 0; i < temps.size(); i++)
    {
        cetak = temps[i];
        cout << cetak.n << ") "
        << cetak.d  << " " << cetak.m  << " " << cetak.y << endl;
    }
    ////////////////////////////////vector Date///////////////////////////////
    int hh,bb,tt;
    vector <Date> tmp;
    Date tanggal{tt,bb,hh};
    cout << "input tanggal :\n"; // ketik dengan format (termasuk koma dan kurung) => (tgl,bulan,tahun)
    
    while (cin >> tanggal) {
        tanggal.init_day(tt,bb,hh);
        tmp.push_back(tanggal);
	}
    // cara stop while (cin) yaitu dengan menekan ctrl + Z pada keyboard, lalu enter
    //sumber : https://stackoverflow.com/questions/50999994/c-when-will-whilecins-stop
    for (size_t i = 0; i < tmp.size(); i++)
    {
        tanggal = tmp[i];
        cout << i << ") " << tanggal <<endl;
    }
    return 0;
}