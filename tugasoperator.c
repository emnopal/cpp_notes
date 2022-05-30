/*
 * =====================================================================================
 *
 *       Filename:  tugasoperator.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/20/2018 10:37:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Muhammad Naufal Shidqi (), mhmmdnflshdq@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int a=3, b=4, c=5, d=8;

int main ()
{
    printf("%d == 4    adalah %d\n", a, a == 4);
    printf("%d == %d   adalah %d\n", a, b, a == b);
    printf("%d < %d    adalah %d\n", c, d, c < d);
    printf("%d != '%d' adalah %d\n", c, 'a', c != 'a');
    printf("%d <= %d   adalah %d\n", b, a, b <= a);
    printf("%d >= 2    adalah %d\n", c, c >= 2);
    
    getchar();
    return(0);
}

