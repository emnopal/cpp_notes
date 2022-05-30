#include "tanggal.h"

void init_day(tanggal& dd, int y, int m, int d)  // check for valid date and initialize
{
    if ((m > 12) || (m<=0))     // pernyataan salah
    {
        error("input bulan antara 1 ~ 12");
    }
    else if (d<=0)
    {
        error("input tanggal antara 1 ~ 31");
    }
    // https://materiku86.blogspot.com/2016/04/perhitungan-kalender-masehi-dan-hijriah.html
    else if (m==2)
    {
        if (d>=30) // tahun kabisat
        {
            if(y%400==0) error("tanggal februari pada tahun kabisat tidak lebih dari 29");
            if((y%400!=0) && (y%100!=0))
            {
                if(y%4==0) error("tanggal februari pada tahun kabisat tidak lebih dari 29");
            }
        }
        if(d>=29) // tahun biasa
        {
            if ((y%400!=0) && (y%100==0)) error("tanggal februari tidak lebih dari 28");
            if((y%400!=0) && (y%100!=0))
            {
                if(y%4!=0) error("tanggal februari tidak lebih dari 28");
            }
        }
    }
    //https://id.wikipedia.org/wiki/Bulan_(penanggalan)
    else if ((m==4) || (m==6) || (m==9) || (m==11))
    {
        if (d>=31)
        {
            error("tanggal pada bulan tersebut tidak lebih dari 30");
        }
    }
    else if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12))
    {
        if (d>=32)
        {
            error("tanggal pada bulan tersebut tidak lebih dari 31");
        }
    }
    else   //pernyataan benar
    {
        dd.thn = y;
        dd.bln = m;
        dd.hr = d;
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
    cout << "tanggal lahir\t\t: "
    << d << " " << cc << " " << y << endl;
}