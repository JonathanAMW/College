#include <stdio.h>

int main(){
    awalan:
    int n, baris, kolom, hasil;
    char pilihan;

    printf("Silakan masukkan input: "); scanf("%d", &n);

    for(kolom=1; kolom<=n; kolom++){
      printf("%d", kolom);
      //awalnya loop ke-2 akan diskip
      for(baris=2; baris<=kolom; baris++){
        printf("%3d", kolom);

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
