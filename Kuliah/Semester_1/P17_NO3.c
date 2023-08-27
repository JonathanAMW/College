//stdio.h adalah library standart dari bahasa c 
#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int main(){
    char array[SIZE], kar;
    int i=0;

    printf("Mengubah bahasa ke B1FF\n");
    printf("====================================\n");
    printf("Masukkan kata (maks 100): ");

    //menerima input
    while((kar = getchar()) != '\n'){
        kar = toupper(kar);
        array[i] = kar;
        i++;
    }

    printf("Dalam bahasa B1FF: ");
    //mengolah input
    for(int j=0; j<i; j++){

        if(array[j]=='A'){
            printf("4");

        }else if(array[j]=='B'){
            printf("8");

        }else if(array[j]=='E'){
            printf("3");

        }else if(array[j]=='I'){
            printf("1");

        }else if(array[j]=='O'){
            printf("0");
        
        }else if(array[j]=='S'){
            printf("5");

        }else
            printf("%c", array[j]);
        
    }

    //memprint tanda seru
    for(int k=0; k<=10; k++){
        printf("!");
    }
    

    return 0;
}