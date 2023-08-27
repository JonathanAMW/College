#include <stdio.h>

int main(){
    awalan:
    int n, i=0, x=0, y=0, j;
    char pilihan;
    
    printf("Silakan masukkan input: "); scanf("%d", &n);

    while(i<=n){
      i++;
      x=x+y;
      printf("%d  ", x);

      for(j=0; j<1; j++){
        y++;

      }

    }

    pertanyaan:
    printf("\napakah anda ingin keluar (y/t)?\n"), scanf(" %c", &pilihan);
    switch(pilihan){
      case 'y':
      goto done;
      break;

      case 't':
      goto awalan;
      break;

      default:
      goto pertanyaan;
      break;
    
    }
    
    done:
    printf("Mematikan sistem, silakan menekan tombol apapun!\n");
    //pause system
    getchar();
    getchar();  
   
    return 0;
}
