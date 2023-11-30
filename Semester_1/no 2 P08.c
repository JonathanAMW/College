#include <stdio.h>

int main(){
    int bil;
    int hasil=0; 
    int max;

    printf("Masukkan sebuah bilangan : "), scanf("%d", &max);

    for(bil=max; bil>=1; bil--){
    hasil = bil + hasil;

    }

    printf("Bilangan triangular %d adalah %d \n", max ,hasil);
    getchar();
    getchar();
    return 0;
}