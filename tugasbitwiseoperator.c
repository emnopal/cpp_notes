/*
 * =====================================================================================
 *
 *       Filename:  tugasbitwiseoperator.c
 *
 *    Description:  tugas operatot bitwise
 *
 *        Version:  1.0
 *        Created:  09/20/2018 11:37:38 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Muhammad Naufal Shidqi (), mhmmdnflshdq@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int a = 6, b = 7, c = 'a';
int x, y;

int main ()
{
    x = (a + b) >= 10;      /* nilai logical statement pertama */
    y = !(c == 'A');        /* nilai logical statement kedua */

    printf("(%d + %d) >= 10 adalah %d\n", a, b, x);
    printf("!(%d == %d) adalah %d\n", c, 'A', y);

    /* nilai logical statement pertama && logical statement kedua */
    printf("%d + %d >= 10 && !(%d == %d) adalah %d\n", a, b, c, 'A', x && y);
    
    getchar();
    return(0);
}

