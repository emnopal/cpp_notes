/*
 * =====================================================================================
 *
 *       Filename:  integral.c
 *
 *    Description:  Menghitung integral dengan batas tertentu dari sebuah fungsi linier
 *
 *        Version:  1.0
 *        Created:  10/04/2018 11:14:18 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Muhammad Naufal Shidqi (), mhmmdnflshdq@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "stdafx.h"
#include <stdio.h>

char line[50];              /* Tempat sementara input */
float i;                    /* Hasil integral */
float dx;                   /* Jumlah kecil grafik */
float r, s;                 /* Fungsi linier */
int a, b;                   /* Batas integral */

/* Membuat fungsi fx */
float f(float r, float s, float x)
{
    float fungsi;
    fungsi = r + (s * x);
    return(fungsi);
}

int main ()
{
    /* Membaca input r dan s untuk fungsi r + sx */
    printf("Masukkan nilai r dan s dari fungsi linier (r + sx) (pisahkan dengan spasi): \n");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%f %f", &r, &s);
    
    /* Membaca input batas integral */
    printf("Masukkan batas integral dari a sampai b (pisahkan dengan spasi): \n");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d %d", &a, &b );

    /* Rumus bagian kecil integral */
    dx = (b-a)/2;

    /* Rumus integral */
    i = i + ((dx * (f(r, s, a) + f(r, s, b))));

    printf("Hasil integral dari %0.3f + (%0.3fx) dengan batas %d sampai %d adalah %0.3f\n", r, s, a, b, i);
    
    getchar();
    return(0);
}
