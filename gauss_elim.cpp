/************* Gauss elimination for solving linear equations *************/

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int n,i,j,k,temp;
    float a[10][10],c,d[10]={0};
    printf("Ini adalah Metode Eliminasi Gauss.");
    printf(" Metode ini digunakan untuk mencari solusi dari persamaan linear n variabel.");
    printf(" Untuk mencari koefisien dari variabel.");
    printf(" Contoh Untuk X = n; Y = b dsb.");
    printf("\n\n");
    cout<<"Berapa dimensi?  ";
    cin>>n;
   // cout<<"Coefficient of all : \n";
    for(i=0;i<n;i++)
    {
        cout<<"Baris : "<<i+1<< "   ";
        for(j=0;j<=n;j++)
            cin>>a[i][j];
    }
    for(i=n-1;i>0;i--)        // partial pivoting
    {
        if(a[i-1][0]<a[i][0])
            for(j=0;j<=n;j++)
            {
                c=a[i][j];
                a[i][j]=a[i-1][j];
                a[i-1][j]=c;
            }
    }
    //*************** DISPLAY MATRIX*************//
    printf("\n\n");
    cout<<"Matriksnya adalah: ";
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
            printf("%6.1f",a[i][j]);
        printf("\n");
    }
    //********* changing to upper triangular matrix*************//
    //********* Forward elimination process**************//
    for(k=0;k<n-1;k++)
        for(i=k;i<n-1;i++)
        {
            c= (a[i+1][k]/a[k][k]) ;
            
            for(j=0;j<=n;j++)
                a[i+1][j]-=c*a[k][j];
        }

     // ************DISPLAYING UPPER TRIANGULAE MATRIX***************//
    printf("\n\n");
    cout<<"Dengan metode Matriks Triangular, maka matriksnya: ";
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
            printf("%6.1f",a[i][j]);
            
        printf("\n");
    }
    //***************** Backward Substitution method****************//

    for(i=n-1;i>=0;i--)
    {
        c=0;
        for(j=i;j<=n-1;j++)
            c=c+a[i][j]*d[j];
            
        d[i]=(a[i][n]-c)/a[i][i];
    }
    //******** RESULT DISPLAY *********//
    printf("\n\n");
    cout<<"Hasilnya adalah: ";
    printf("\n\n");
    for(i=0;i<n;i++)
    cout<<d[i]<<endl;


    _getch();
    return 0;
}

