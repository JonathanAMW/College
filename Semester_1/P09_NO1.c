#include <stdio.h>

int main() {
  char kar;

  printf("Silakan mengetikkan apapun!\n");
  printf("Sistem akan berhenti setelah anda menginputkan huruf X(x kapital)!\n");

  while (kar != 'X'){
     scanf("%c", &kar);

     printf("%c", kar);
      
  } 

  printf("\nAnda sudah mengetikkan X!\n");
  printf("Sistem telah berhenti!\n");

  getchar();
  getchar();

  return 0;
}