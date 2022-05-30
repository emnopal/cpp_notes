/*
 * =====================================================================================
 *
 *       Filename:  Program-rumus-naufal.c
 *
 *    Description:  Rumus kecepatan akhir
 *
 *        Version:  1.1
 *        Created:  09/13/2018 12:34:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Muhammad Naufal Shidqi (), mhmmdnflshdq@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

char line[100];     /* Penyimpanan sementara input */
float v_awal, v_akhir, percepatan, waktu;

int main ()
{
   printf("Masukkan nilai kecepatan awal (jarak/waktu): ");
   fgets(line, sizeof(line), stdin);
   sscanf(line, "%f", &v_awal);
   
   printf("Masukkan nilai percepatan (jarak/waktu^2): ");
   fgets(line, sizeof(line), stdin);
   sscanf(line, "%f", &percepatan);
   
   printf("Masukkan nilai waktu (waktu): ");
   fgets(line, sizeof(line), stdin);
   sscanf(line, "%f", &waktu);
   
   v_akhir = (2 * v_awal + percepatan * waktu) / 2;

   printf("Percepatan akhirnya adalah %f (jarak/waktu)\n", v_akhir);
   
   getchar();
   return (0);
}
