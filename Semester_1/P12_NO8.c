//stdio.h adalah library standard untuk bahasa c
#include <stdio.h>

int main(){
   int i, j, batas, total=0;

   printf("Inputkan batas bilangan "), scanf("%d", &batas);

    for(i=1; i<=batas; i++){
        for(j=1; j<i; j++){
            if(i%j==0||j==1){
                total=total+j;
            }

        }

        if(total==i && total!=1){
        printf("%d ", total);

        } 

        total=0;
    }

   //system pause
    getchar();
    getchar();
    return 0;
}