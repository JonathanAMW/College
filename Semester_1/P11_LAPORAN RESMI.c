#include <stdio.h>

int main(){
    awalan:
    int total, input, n, i, x, hasil;
    char pilihan;

    printf("Silakan masukkan input: "); scanf("%d", &input);
    x=input;
    total=input;
    
    for(n=input; n>1; n--){ //berjalan sampai n mencapai 1
      for(i=n; i>2; i--){ //berjalan sampai i mencapai 2
        hasil=0;
        hasil+=x;
        total+=hasil;

      }
      x=total;

    }
    printf("hasil faktorial dari %d! adalah: %d", input, total);

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
