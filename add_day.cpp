#include "tanggal.h"

void add_day(int y, int m, int d)
{
    cout << "\ntambah hari : ";
    int tambah;
    cin >> tambah;
    if (tambah < 0) error("tidak dapat mengurangi hari");
    //if (tambah > 31) error("tidak dapat lebih dari 31");
    int hasiltambah = d + tambah;
    ///////////////////////////////////////////////////////////////////
    if (m==2)
    {
        if (hasiltambah > 29)
        {
            if(y%400==0)
            {
                m++;
                hasiltambah -= 29;
            }
            if((y%400!=0) && (y%100!=0))
            {
                if(y%4==0)
                {
                    m++;
                    hasiltambah -= 29;
                }
            }
        }
        if (hasiltambah > 28)
        {
            if ((y%400!=0) && (y%100==0))
            {
                m++;
                hasiltambah -= 28;
            }
            if((y%400!=0) && (y%100!=0))
            {
                if(y%4!=0)
                {
                    m++;
                    hasiltambah -= 28;
                }
            }
        }
    }
    if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12))
    {
        if (hasiltambah > 31)
        {
            m++;
            hasiltambah -= 31;
        }
    }
    if((m==4) || (m==6) || (m==9) || (m==11))
    {
        if(hasiltambah > 30)
        {
            m++;
            hasiltambah -= 30;
        }
    }
    if (m > 12)
    {
        y++;
        m -= 12;
    }
    ///////membuat kapasitas agar pertambahan hari bisa lebih banyak/////////////
    ////////(menugaskan hasiltambah lama ke hasiltambah yang baru)///////////////
    {
        if (tambah > 365) error("tidak dapat lebih dari 365");
        ////////////////////////////////////////////////////////////////////////////
            if (m==2)
            {
                if (hasiltambah > 29)
                {
                    if(y%400==0)
                    {
                        m++;
                        hasiltambah -= 29;
                    }
                    if((y%400!=0) && (y%100!=0))
                    {
                        if(y%4==0)
                        {
                            m++;
                            hasiltambah -= 29;
                        }
                    }
                }
                if (hasiltambah > 28)
                {
                    if ((y%400!=0) && (y%100==0))
                    {
                        m++;
                        hasiltambah -= 28;
                    }
                    if((y%400!=0) && (y%100!=0))
                    {
                        if(y%4!=0)
                        {
                            m++;
                            hasiltambah -= 28;
                        }
                    }
                }
            }
            if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12))
            {
                if (hasiltambah > 31)
                {
                    m++;
                    hasiltambah -= 31;
                }
            }
            if((m==4) || (m==6) || (m==9) || (m==11))
            {
                if(hasiltambah > 30)
                {
                    m++;
                    hasiltambah -= 30;
                }
            }
            if (m > 12)
            {
                y++;
                m -= 12;
            }
        ////////////////////////////////////////////////////////////////////////////
            if (m==2)
            {
                if (hasiltambah > 29)
                {
                    if(y%400==0)
                    {
                        m++;
                        hasiltambah -= 29;
                    }
                    if((y%400!=0) && (y%100!=0))
                    {
                        if(y%4==0)
                        {
                            m++;
                            hasiltambah -= 29;
                        }
                    }
                }
                if (hasiltambah > 28)
                {
                    if ((y%400!=0) && (y%100==0))
                    {
                        m++;
                        hasiltambah -= 28;
                    }
                    if((y%400!=0) && (y%100!=0))
                    {
                        if(y%4!=0)
                        {
                            m++;
                            hasiltambah -= 28;
                        }
                    }
                }
            }
            if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12))
            {
                if (hasiltambah > 31)
                {
                    m++;
                    hasiltambah -= 31;
                }
            }
            if((m==4) || (m==6) || (m==9) || (m==11))
            {
                if(hasiltambah > 30)
                {
                    m++;
                    hasiltambah -= 30;
                }
            }
            if (m > 12)
            {
                y++;
                m -= 12;
            }
        ////////////////////////////////////////////////////////////////////////////
            if (m==2)
            {
                if (hasiltambah > 29)
                {
                    if(y%400==0)
                    {
                        m++;
                        hasiltambah -= 29;
                    }
                    if((y%400!=0) && (y%100!=0))
                    {
                        if(y%4==0)
                        {
                            m++;
                            hasiltambah -= 29;
                        }
                    }
                }
                if (hasiltambah > 28)
                {
                    if ((y%400!=0) && (y%100==0))
                    {
                        m++;
                        hasiltambah -= 28;
                    }
                    if((y%400!=0) && (y%100!=0))
                    {
                        if(y%4!=0)
                        {
                            m++;
                            hasiltambah -= 28;
                        }
                    }
                }
            }
            if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12))
            {
                if (hasiltambah > 31)
                {
                    m++;
                    hasiltambah -= 31;
                }
            }
            if((m==4) || (m==6) || (m==9) || (m==11))
            {
                if(hasiltambah > 30)
                {
                    m++;
                    hasiltambah -= 30;
                }
            }
            if (m > 12)
            {
                y++;
                m -= 12;
            }
        ////////////////////////////////////////////////////////////////////////////
            if (m==2)
            {
                if (hasiltambah > 29)
                {
                    if(y%400==0)
                    {
                        m++;
                        hasiltambah -= 29;
                    }
                    if((y%400!=0) && (y%100!=0))
                    {
                        if(y%4==0)
                        {
                            m++;
                            hasiltambah -= 29;
                        }
                    }
                }
                if (hasiltambah > 28)
                {
                    if ((y%400!=0) && (y%100==0))
                    {
                        m++;
                        hasiltambah -= 28;
                    }
                    if((y%400!=0) && (y%100!=0))
                    {
                        if(y%4!=0)
                        {
                            m++;
                            hasiltambah -= 28;
                        }
                    }
                }
            }
            if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12))
            {
                if (hasiltambah > 31)
                {
                    m++;
                    hasiltambah -= 31;
                }
            }
            if((m==4) || (m==6) || (m==9) || (m==11))
            {
                if(hasiltambah > 30)
                {
                    m++;
                    hasiltambah -= 30;
                }
            }
            if (m > 12)
            {
                y++;
                m -= 12;
            }
        ////////////////////////////////////////////////////////////////////////////
            if (m==2)
            {
                if (hasiltambah > 29)
                {
                    if(y%400==0)
                    {
                        m++;
                        hasiltambah -= 29;
                    }
                    if((y%400!=0) && (y%100!=0))
                    {
                        if(y%4==0)
                        {
                            m++;
                            hasiltambah -= 29;
                        }
                    }
                }
                if (hasiltambah > 28)
                {
                    if ((y%400!=0) && (y%100==0))
                    {
                        m++;
                        hasiltambah -= 28;
                    }
                    if((y%400!=0) && (y%100!=0))
                    {
                        if(y%4!=0)
                        {
                            m++;
                            hasiltambah -= 28;
                        }
                    }
                }
            }
            if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12))
            {
                if (hasiltambah > 31)
                {
                    m++;
                    hasiltambah -= 31;
                }
            }
            if((m==4) || (m==6) || (m==9) || (m==11))
            {
                if(hasiltambah > 30)
                {
                    m++;
                    hasiltambah -= 30;
                }
            }
            if (m > 12)
            {
                y++;
                m -= 12;
            }
        ////////////////////////////////////////////////////////////////////////////
            if (m==2)
            {
                if (hasiltambah > 29)
                {
                    if(y%400==0)
                    {
                        m++;
                        hasiltambah -= 29;
                    }
                    if((y%400!=0) && (y%100!=0))
                    {
                        if(y%4==0)
                        {
                            m++;
                            hasiltambah -= 29;
                        }
                    }
                }
                if (hasiltambah > 28)
                {
                    if ((y%400!=0) && (y%100==0))
                    {
                        m++;
                        hasiltambah -= 28;
                    }
                    if((y%400!=0) && (y%100!=0))
                    {
                        if(y%4!=0)
                        {
                            m++;
                            hasiltambah -= 28;
                        }
                    }
                }
            }
            if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12))
            {
                if (hasiltambah > 31)
                {
                    m++;
                    hasiltambah -= 31;
                }
            }
            if((m==4) || (m==6) || (m==9) || (m==11))
            {
                if(hasiltambah > 30)
                {
                    m++;
                    hasiltambah -= 30;
                }
            }
            if (m > 12)
            {
                y++;
                m -= 12;
            }
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
    cout << "tanggal lahir + " << tambah << "\t: "
    << hasiltambah << " " << cc << " " << y << endl;
}