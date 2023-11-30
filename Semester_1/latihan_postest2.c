#include <stdio.h>

int main(){
    int input, i, j;
    printf("Silakan masukkan input: "), scanf("%d", &input);

    for(i=1; i<=input; i++){
      printf("\n");
      for(j=i; j>=1; j--){
        printf("%d", j);
      }

    }

    i=0;
    j=0;
    for(i=input-1; i>=1; i--){
      printf("\n");
      for(j=i; j>=1; j--){
        printf("%d", j);
      }

    }
    //pause system
    getchar();
    getchar();

   return 0;
}
