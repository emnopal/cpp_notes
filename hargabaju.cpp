#include <stdio.h>

int main ()
{
    char line[50];
    char merk[1][5][15] = {"merk1", "merk2", "merk3", "merk4", "merk5"};
    char size[1][4][5] = {"S", "M", "L", "XL"};
    char harga[5][4][15] =
    {
        "Rp50000", "Rp55000", "Rp60000", "Rp65000",
        "Rp100000", "Rp110000", "Rp120000", "Rp130000",
        "Rp150000", "Rp170000", "Rp190000", "Rp210000",
        "Rp200000", "Rp230000", "Rp260000", "Rp290000",
        "Rp250000", "Rp290000", "Rp330000", "Rp370000"
    };
    int i, a, b;

    for(i=0; i<5; i++)
    {
        printf("%d. %s\n", i+1, merk[0][i]);
    }
    printf("Pilih merk baju yang anda inginkan: ");
    
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &a);

    for(i=0; i<4; i++)
    {
        printf("%d. %s\n", i+1, size[0][i]);
    }
    printf("Silahkan pilih ukuran baju yang anda inginkan: ");
    
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &b);

    printf("Harga baju dengan merk %s ukuran %s adalah %s", merk[0][a-1], size[0][b-1], harga[a-1][b-1]);

    getchar();
    return(0);

}

