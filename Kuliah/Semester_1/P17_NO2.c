//stdio.h adalah library standart dari bahasa c 
#include <stdio.h>
#define SIZE 10

int main(){
    //mengapa [10]? karena int memiliki jumlah digits kurang dari 10 digits
    int bil, array[SIZE], n=0;

    printf("Menampilkan berapa kali angka muncul\n");
    printf("====================================\n");
    printf("Masukkan bilangan(maks 10 baris dan harus bilangan bulat positif/nol): "), scanf("%d", &bil);
    printf("\n");

    //pengambilan angka
    while(bil!=0){
        int angka=0;
        angka=bil%10;
        array[n]=angka;
        bil/=10;
        n++;

    }
    
    printf("Angka:   0  1  2  3  4  5  6  7  8  9");
    printf("\nMuncul:  ");

    for(int i=0; i<SIZE; i++){
        int counter=0;
        for(int j=0; j<SIZE; j++){
            if(i==array[j]){
                counter++;
            }else
                continue;
        }

        if(counter==0){
            printf("0  ");
            
        }else
            printf("%d  ", counter);
    }
    

    return 0;
}