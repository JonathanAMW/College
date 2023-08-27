#include <stdio.h>

int main(){
    int n; //maksimal
    int i; //penghitung atau pengatur
    int x = 0; //awal bilangan pertama

    printf("Masukkan jumlah bilangan yang ingin difaktorialkan untuk ditampilkan: "), scanf("%d", &n);

    for(i = 1; i < n; i++){
        x = x+1;
        printf("%d*",x);
        
    }

    int y=n;//awal bilangan kedua
    printf("%d", y);

    getchar();
    getchar();

    return 0;
}
