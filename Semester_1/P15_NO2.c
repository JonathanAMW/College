//stdio.h adalah library standart untuk c
#include <stdio.h> 

int main() {
    int fibonanci[100], jumlah;
    fibonanci[0]=0;
    fibonanci[1]=1;

    printf("Berapa kali deret fibonanci ingin ditampilkan?: "), scanf("%d", &jumlah);
    
    //penyuluhan/assigment
    for(int i=1; i<=jumlah; i++){
        int total=0;
        //penjumlahan
        total=fibonanci[i]+fibonanci[i-1];
        //pentotalan
        fibonanci[i+1]=total;

    }

    printf("\n");
    printf("Deret fibonanci tersebut adalah sebagai berikut:\n");

    //penampilan
    for(int j=0; j<jumlah; j++){
        printf("%d ", fibonanci[j]);

    }

    return 0;
}