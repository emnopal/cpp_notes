#include <stdio.h>

char    line[50];
float   beratbadanideal, beratbadan, tinggibadan;

int main ()
{
    printf("Masukkan berat badan anda: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%f", &beratbadan);
    
    printf("Masukkan tinggi badan: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%f", &tinggibadan);
    
    beratbadanideal = (tinggibadan - 100) - 0.1 * (tinggibadan - 100);

    printf("Berat badan idealmu adalah %f\n", beratbadanideal);

    if(beratbadan > (beratbadanideal + 5))
        printf("Anda terlalu gemuk");

    if(beratbadan < (beratbadanideal - 5))
        printf("Anda terlalu kurus");
    
    else
        printf("Berat badan anda ideal");

    getchar();
    return(0);
}

