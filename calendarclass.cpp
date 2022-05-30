#include "std_lib_facilities.h"

class Date
{
public:
	Date(int yy, int mm, int dd); //constructor
	void add_day(int n);
	void mult_month(int mm);

private:
	int y, m, d;
};

enum month
{
	jan = 1,
	feb,
	mar,
	apr,
	mei,
	jun,
	jul,
	ags,
	sep,
	okt,
	nov,
	des
};

Date::Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} // check for valid date and initialize
{
	if ((m > des) || (m < jan)) // pernyataan salah disini
	{
		error("input bulan antara 1 ~ 12");
	}
	else if (d <= 0)
	{
		error("input tanggal antara 1 ~ 31");
	}
	else if (m == feb)
	{
		if (d >= 30)
		{
			error("tanggal pada bulan tersebut tidak lebih dari 29");
		}
	}
	else if ((m == apr) || (m == jun) || (m == sep) || (m == nov))
	{
		if (d >= 31)
		{
			error("tanggal pada bulan tersebut tidak lebih dari 30");
		}
	}
	else if ((m == jan) || (m == mar) || (m == mei) || (m == jul) || (m == ags) || (m == okt) || (m == des))
	{
		if (d >= 32)
		{
			error("tanggal pada bulan tersebut tidak lebih dari 31");
		}
	}
	else //pernyataan benar
	{
		yy = y;
		mm = m;
		dd = d;
	}
	string cc = to_string(m);
	if (m == jan)
		cc = "Januari";
	if (m == feb)
		cc = "Februari";
	if (m == mar)
		cc = "Maret";
	if (m == apr)
		cc = "April";
	if (m == mei)
		cc = "Mei";
	if (m == jun)
		cc = "Juni";
	if (m == jul)
		cc = "Juli";
	if (m == ags)
		cc = "Agustus";
	if (m == sep)
		cc = "September";
	if (m == okt)
		cc = "Oktober";
	if (m == nov)
		cc = "November";
	if (m == des)
		cc = "Desember";
	cout << "tanggal lahir\t\t: "
		 << d << " " << cc << " " << y << endl;
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
		error("tidak dapat mengurangi hari");
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
		cc = "Januari";
	if (m == 2)
		cc = "Februari";
	if (m == 3)
		cc = "Maret";
	if (m == 4)
		cc = "April";
	if (m == 5)
		cc = "Mei";
	if (m == 6)
		cc = "Juni";
	if (m == 7)
		cc = "Juli";
	if (m == 8)
		cc = "Agustus";
	if (m == 9)
		cc = "September";
	if (m == 10)
		cc = "Oktober";
	if (m == 11)
		cc = "November";
	if (m == 12)
		cc = "Desember";
	cout << "tanggal lahir + " << n << "\t: "
		 << hasiltambah << " " << cc << " " << y << endl;
}

int main()
{
	cout << "M. Galih R\n";
	int hh, bb, tt;
	cout << "Masukkan tanggal lahir  \n";
	cout << "Tanggal\t: ";
	cin >> hh;
	cout << "Bulan\t: ";
	cin >> bb;
	cout << "Tahun\t: ";
	cin >> tt;

	Date kalender{tt, bb, hh};

	cout << "\ntambah hari : ";
	int tambah;
	cin >> tambah;

	kalender.add_day(tambah);
	return 0;
}