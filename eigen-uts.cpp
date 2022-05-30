#include <stdio.h>
#include <math.h>
char line[100];

int main ()
{
    int n, i, j;
    double a[50][50], b[50], c[50], k, eps, y;

    printf("Masukkan ordo matriks: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d\n", &n);
    
    printf("Masukkan elemen matriks:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("a[%d][%d] = ", i+1, j+1);
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%lf\n", &a[i][j]);
        }
    }
    printf("Masukkan tebakan awal dari eigen-vektor:\n");
    for(i=0; i<n; i++)
    {
        printf("b[%d] = ", i+1);
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%lf\n", &b[i]);
    }
    printf("Masukkan akurasi yang diinginkan:\n");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%lf", &eps);
    
    k = b[0];

    do
    {
        y = k;
        for(i=0; i<n; i++)
        {
            c[i] = 0;
            for(j=0; j<n; j++)
            {
                c[i] = c[i] + a[i][j] * b[j];
            }
        }
        k = fabs(c[0]);
        for(i=1; i<n; i++)
        {
            k = fabs(c[i])> k? fabs(c[i]) : k;
        }
        for(i=0; i<n; i++)
        {
            b[i] = c[i] / k;
        }
    }
    while(fabs(k-y)>eps);
    printf("Nilai eigen dari matriks tersebut adalah %f\n", k);
    printf("dan vektor eigennya adalah [");
    for(i=0; i<n; i++)
    {
        printf("%7.3f", b[i]);
    }
    printf("]\n");
    
    getchar();
    return(0);
}

/* Disadur dan diubah sesuai kebutuhan dari https://www.bragitoff.com/2015/10/eigen-value-and-eigen-vector-of-a-matrix-by-iterative-method-c-program/ */
