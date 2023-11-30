#include <stdio.h>

int main(){
    int a, b, c, d, geser;

    printf("inputkan a: "), scanf("%d", &a);
    printf("inputkan b: "), scanf("%d", &b);
    printf("inputkan c: "), scanf("%d", &c);
    printf("inputkan d: "), scanf("%d", &d);

    printf("Angka yang anda masukkan adalah a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    printf("Mau geser ke kiri berapa kali?: "), scanf(" %d", &geser);
    printf("\n");

    int a1=a, b1=b, c1=c, d1=d;
    int i, j;
    for(i=geser; i>0; i--){
        for(j=i; j>0; j--){
            a=b1, b=c1, c=d1, d=a1;

        }
        a1=a, b1=b, c1=c, d1=d;

    }
    
    printf("hasil setelah proses penggeseran :\n");
    printf("a=%d, b=%d, c=%d, d=%d", a, b, c, d);

    //system pause
    getchar();
    getchar();
    return 0;
}