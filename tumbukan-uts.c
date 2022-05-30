/*
 * =====================================================================================
 *
 *       Filename:  tumbukan-uts.c
 *
 *    Description:  Menghitung berbagai jenis tumbukan antara dua benda
 *
 *        Version:  1.0
 *        Created:  10/26/2018 08:10:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Muhammad Naufal Shidqi (), mhmmdnflshdq@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
char line[100];

/* Fungsi untuk menghitung tumbukan */
void tumbukan(float e, float m1, float m2, float V1awal, float V2awal)
{
    float V2akhir, V1akhir;
    V2akhir = (m1 * (V1awal - e * (V2awal - V1awal)) + m2 * V2awal) / (m1 + m2);
    V1akhir = e * (V2awal - V1awal) + V2akhir;
    
    printf("Arah dan kecepatan benda pertama setelah tumbukan adalah %.3f m/s\n", V1akhir);
    printf("Arah dan kecepatan benda kedua setelah tumbukan adalah %.3f m/s\n", V2akhir);
    return;
}

int main ()
{
    /* Variabel bagian dari rumus tumbukan */
    float m1, m2, V1awal, V2awal, e;
    /* Variabel untuk pilihan tumbukan */
    int o;
    /* Variabel untuk pengulangan */
    char r;

    r = 'y';
    while(r == 'y' || r == 'Y')
    {

        printf("Masukkan massa (kg) dan kecepatan awal benda pertama (m/s) dipisah dengan spasi: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%f %f\n", &m1, &V1awal);

        printf("Masukkan massa (kg) dan kecepatan awal benda kedua (m/s) dipisah dengan spasi: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%f %f\n", &m2, &V2awal);

        printf("\n"); 

        printf("1. Tumbukan Lenting Sempurna\n");
        printf("2. Tumbukan Lenting Sebagian\n");
        printf("3. Tumbukan Tidak Lenting Sama Sekali\n");
        printf("Pilih tumbukan yang ingin anda hitung: \n");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d\n", &o);
        
        if(o == 1)
        {
            printf("\n");
            tumbukan(1, m1, m2, V1awal, V2awal);
            printf("\n");
        }
        if(o == 2)
        {
            printf("\n");
            printf("Masukkan nilai koefisen restitusi (0<e<1): ");
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%f", &e);

            printf("\n");
            tumbukan(e, m1, m2, V1awal, V2awal);
            printf("\n");
        }
        if(o == 3)
        {
            printf("\n");
            tumbukan(0, m1, m2, V1awal, V2awal);
            printf("\n");
        }
        else
        {
            printf("Tumbukan tidak tersedia\n");
        }

        printf("Apakah anda ingin mengulang program? (y/n)\n");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%c", &r);
    }

    return(0);

}

