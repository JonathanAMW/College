#include <stdio.h>

int main(){
    int n; //maksimal
    int i; //penghitung atau pengatur
    int x = -1; //awal bilangan pertama
    int y = 0; //awal bilangan kedua

    printf("Masukkan jumlah bilangan ganjil yang ingin ditampilkan: "), scanf("%d", &n);

    for(i = 1; i <= n/2; i++){
        x = x+2;
        y = y-2;
        printf("%d %d ", x, y);
        
    }

    getchar();
    getchar();

    return 0;
}
