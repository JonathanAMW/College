#include <stdio.h>

int main(){
    int n, i=0, x=-1;

    printf("Berapa banyak bilangan ganjil kecuali dapat dibagi 3 yang anda ingin tampilkan?: "), scanf("%d", &n);

    while(n > i){
      x=x+2;

      if(x % 3 == 0){
        continue;

      } else 
        printf("%d\n", x);
         i++;

    }

    //pause system
    getchar();
    getchar();

    return 0;
}
