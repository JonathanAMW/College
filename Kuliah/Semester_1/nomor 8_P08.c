#include <stdio.h>

int main(){
    char pilihan = 'y'; //pilihan
    int bil; //awal bilangan pertama
    int total=0;
    int i=0;

    while (pilihan == 'y'|| pilihan == 'Y'){
        i++;

        printf("Masukkan bilangan ke-%d : ", i), scanf("%d", &bil);
        total = total+bil;

        printf("Mau memasukkan data lagi [y/t]? ");
        //perlu dispasi seperti (spasi)%c agar enter tidak dibaca
        scanf(" %c", &pilihan);
        
    }

    printf("Total bilangan = %d", total);

    getchar();
    getchar();

    return 0;
}
