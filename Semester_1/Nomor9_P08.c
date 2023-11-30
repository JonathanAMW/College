#include <stdio.h>

int main(){
    char pilihan = 'y'; //pilihan
    int bil; //awal bilangan pertama
    int total=0;
    int i=0;
    float n;
    float rata;
    int min = 0;
    int max = 0;

    while (pilihan == 'y'|| pilihan == 'Y'){
        i++;
        n=i;

        printf("Masukkan bilangan ke-%d : ", i), scanf("%d", &bil);
        total = total+bil;
        rata = total/n;

        printf("Mau memasukkan data lagi [y/t]? ");
        getchar();

        pilihan=getchar();

       if (max==0 && min==0){
           min=bil;
           max=bil;
        } else if (bil<=min) {
            min=bil;
        } else if (bil>=max) {
            max=bil;
        } else
            continue;
     
    }

    printf("Total bilangan = %d\n", total);
    printf("Rata-rata = %f\n", rata);
    printf("Nilai minimum = %d\n", min);
    printf("Nilai maksimum = %d\n", max);

    getchar();
    getchar();

    return 0;
}
