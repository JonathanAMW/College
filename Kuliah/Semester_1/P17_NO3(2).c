//stdio.h adalah library standart dari bahasa c
#include <stdio.h>
//berguna untuk toupper
#include <ctype.h>
#define max 255

int main(void)
{
    char arraypengganti[max];
   
    for (int i=0;  i<max; i++) {
        arraypengganti[i] = (char)i;
    }
    
    arraypengganti['S'] = '5';
    arraypengganti['O'] = '0';
    arraypengganti['I'] = '1';
    arraypengganti['E'] = '3';
    arraypengganti['B'] = '8';
    arraypengganti['A'] = '4';


    printf("Masukkan kalimat untuk dikonversi ke bahasa B1FF (max 255): ");

    int ch;
    while ((ch = getchar()) != '\n' && ch != -1) {
        putchar(arraypengganti[toupper(ch)]);
    }

    for(int j=0; j<=10; j++){
        printf("!");
    }
        
    return 0;
}