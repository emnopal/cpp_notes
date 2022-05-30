#include <stdio.h>

int main ()
{
    char line[100];
    int i, j, baris, kolom, determinan;
    int matrikA[100][100];

    baris = 2;
    kolom = 2;

    printf("Program untuk menghitung determinan dari Matrik 2x2 A\n\n");

    /* Memasukkan nilai matrikA */
    printf("Masukkan nilai matrik A\n");
    for(i=0; i<baris; i++)
    {
        for(j=0; j<kolom; j++)
        {
            printf("A(%3d,%3d): ", i+1, j+1);
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%d", &matrikA[i][j]);
        }
        printf("\n");
    }

    /* Print matrik A */
    printf("Matrik A: \n");
    for(i=0; i<baris; i++)
    {
        for(j=0; j<kolom; j++)
        {
            printf("%7d", matrikA[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    /* Menghitung determinan */
    determinan = (matrikA[0][0] * matrikA[1][1]) - (matrikA[0][1] * matrikA[1][0]);
    printf("|A| = %d", determinan);

    getchar();
    return(0);
}

