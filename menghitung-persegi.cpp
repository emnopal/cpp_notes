/*
 * =====================================================================================
 *
 *       Filename:  menghitung-persegi.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/14/2018 05:59:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Muhammad Naufal Shidqi (), mhmmdnflshdq@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "stdafx.h"

int main ()
{
    char line[50];
    char oper;
    double operand1;

    puts("Program Menghitug persegi\n");
    puts("Operator yang digunakan: ");
    puts("L => Area\n");
    puts("K => Keliling\n");
    printf("Silahkan masukkan panjang sisi dan operator: \n");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%lf%c", &operand1, &oper);
    
    switch(oper)
    {
        case 'L':
        case 'l':
            printf("Hasil = %.101g", operand1 * operand1);
            break;
            
        case 'K':
        case 'k':
            printf("Hasil = %.101g", operand1 * 4);
            break;

        default:
            puts("Perintah yang anda masukkan salah");
            break;
    }

    getchar();
    return(0);
}

