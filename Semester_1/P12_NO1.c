#include <stdio.h>

int main(){
    int n, awal, mulai, hasil=0;

    printf("inputkan n: "), scanf("%d", &n);
    printf("input angka awal: "), scanf("%d", &awal);
    printf("inputkan mulai: "), scanf("%d", &mulai);

    int i;
    for(i=0; i<n; i++){
        printf("%d  ", awal);
        hasil=hasil+awal;
        awal=awal+mulai+i;
    }

    printf("jumlah: %d", hasil);


    //system pause
    getchar();
    getchar();
    return 0;
}