#include <stdio.h>

int main(){
    int n, i=0, x=-1;

    printf("Berapa banyak bilangan ganjil(kecuali kelipatan 7 dan 11) kurang dari 100 yang anda ingin tampilkan?: "), scanf("%d", &n);

    while(n > i){
      x=x+2;

      if(x%7==0 && x%11==0){
        continue;

      }else if (x >= 100){
        break;

      } else 
        printf("%d\n", x);
         i++;

    }

    //pause system
    getchar();
    getchar();

   return 0;
}
