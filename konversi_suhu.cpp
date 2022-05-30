#include <stdio.h>
char line[100];
/* Fungsi untuk menghitung suhu Celcius */
void konversi_suhu_celcius(float suhu){
    float ctof, ctok;
    ctof = (suhu*(9/5)) + 32;
    ctok = suhu + 273.15;
    printf("Fahrenheit adalah %.2f oF\n", ctof);
    printf("Kelvin adalah %.2f oK\n", ctok);
    return;
}
/* Fungsi untuk menghitung suhu Fahrenheit */
void konversi_suhu_fahrenheit(float suhu){
    float ftoc, ftok;
    ftoc = (suhu*(5/9)) - 32;
    ftok = ((suhu - 32)*(5/9)) + 273.15;
    printf("Celcius adalah %.2f oC\n", ftoc);
    printf("Kelvin adalah %.2f oK\n", ftok);
    return;
}
/* Fungsi untuk menghitung suhu Kelvin */
void konversi_suhu_kelvin(float suhu){
    float ktoc, ktof;
    ktoc = suhu - 273.15;
    ktof = ((suhu - 273.15)*(9/5)) + 32;
    printf("Fahrenheit adalah %.2f oF\n", ktoc);
    printf("Celcius adalah %.2f oC\n", ktof);
    return;
}
int main (){
    /* Variabel bagian dari rumus Konversi Suhu */
    float ctof, ctok, ftoc, ftok, ktoc, ktof, suhu;
    /* Variabel untuk pilihan Konversi Suhu */
    int o;
    /* Variabel untuk pengulangan */
    char r;
    r = 'y';
    while(r == 'y' || r == 'Y'){
        printf("Masukkan suhu: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%f\n", &suhu);
        printf("\n");
        printf("1. Dari Celcius ke Fahrenheit dan Kelvin\n");
        printf("2. Dari Fahrenheit ke Celcius dan Kelvin\n");
        printf("3. Dari Kelvin ke Celcius dan Fahrenheit\n");
        printf("\n");
        printf("Pilih suhu yang ingin dikonversi: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d\n", &o);
        printf("\n");
        if(o == 1){
            printf("1. Konversi dari Celcius ke: \n");
            konversi_suhu_celcius(suhu);
        }
        if(o == 2){
            printf("2. Konversi dari Fahrenheit ke: \n");
            konversi_suhu_fahrenheit(suhu);
        }
        if(o == 3){
            printf("3. Konversi dari Kelvin ke: \n");
            konversi_suhu_kelvin(suhu);
        }
        else{
            printf("\n");
            printf("Pilihan Anda Salah");
        }
        //printf("\n");
        printf("Apakah anda ingin mengulang program? (y/n)");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%c", &r);
    }
    return(0);
}