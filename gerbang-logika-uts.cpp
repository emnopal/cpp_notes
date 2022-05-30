#include <stdio.h>
#include <string.h>
char line[100];

int main ()
{
    int A, B, Y;
    
    printf("Masukkan nilai A (0/1)\n");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &A);
    
    printf("Masukkan nilai B (0/1)\n");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &B);

    printf("%s", line);
    
    Y = A || B;
    printf("%d or %d adalah %d", A, B, Y);
    
    getchar();
    return(0);
}

