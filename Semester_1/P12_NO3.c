#include <stdio.h>

int main(){
    int n, hasil=0;

    printf("inputkan N: "), scanf("%d", &n);
    hasil=n*3;

    int i, j;
    for(i=n; i>0; --i){
     for(j=i; j>0; --j){
         printf("%d ", hasil);
         hasil=hasil-1;
     }
        printf("\n");


    }

    //system pause
    getchar();
    getchar();
    return 0;
}