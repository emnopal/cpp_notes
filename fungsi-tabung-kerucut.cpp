#include <stdio.h>

const float pi=3.14159265359;

/* fungsi volume tabung */
float tabung(float r, float t)
{
    float v;
    v = pi * r * r * t;
    return (v);
}

/* fungsi volume kerucut */
float kerucut(float r, float t)
{
    float v;
    v = pi * r * r * 1/3 * t;
    return (v);
}

int main ()
{
    char line[100];
    float r, t;
    int i;

    printf("Masukkan jari-jari dan tinggi: ");

    fgets(line, sizeof(line), stdin);
    sscanf(line, "%f %f", &r, &t);
    printf("\n");

    for(i=0; i<10; i++)
    {
        printf("%d. Volume tabung dengan jari-jari %7.2f dan tinggi %7.2f adalah %7.2f\n", i+1, r, t, tabung(r, t));
        r += 7;
        t += 7;
    }

    printf("\n");
    
    for(i=0; i<10; i++)
    {
        printf("%d. Volume kerucut dengan jari-jari %7.2f dan tinggi %7.2f adalah %7.2f\n", i+1, r, t, kerucut(r, t));
        r += 7;
        t += 7;
    }
    
    getchar();
    return(0);
}
