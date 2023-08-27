#include <stdio.h>

int main(){
    awalan:
    int maks, baris, kolom, hasil;
    char pilihan;

    printf("Silakan masukkan input: "); scanf("%d", &maks);

    for(kolom=1; kolom<=maks; kolom++){
      //sebagai kolom yang tidak akan berubah
      printf("1");
      for(baris=1; baris<maks; baris++){
        hasil=1+baris;
        printf("%3d", hasil);

      }
      printf("\n");

    }

    pertanyaan:
    printf("apakah anda ingin keluar (y/t)? "), scanf(" %c", &pilihan);
    switch(pilihan){
      case 'y':
      goto done;
      break;

      case 't':
      goto awalan;
      break;

      default:
      goto pertanyaan;
    
    }
    
    done:
    printf("Mematikan sistem, silakan menekan tombol apapun!\n");
    //pause system
    getchar();
    getchar();
    
   return 0;
}
