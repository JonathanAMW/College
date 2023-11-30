#include <stdio.h>

int main(){
    int total=0, x, y;

    printf("Silakan masukkan nilai secara berurutan tanpa spasi: "); scanf("%d", &x);

    while(x != 0){
      //pertama diambil dulu angka terakhir dengan memodulonya menggunakan 10
      y=x%10;
      //kemudian untuk menghilangkan angka terakhir, input dibagi dengan 10 untuk menyisakan angka input didepannya
      x/=10; // x=x/10
      //angka terakhir tadi, ditotal disini
      total+=y; // total=total+y
    }
    printf("Jumlah angka tersebut adalah: %d", total);

    //pause system
    getchar();
    getchar();

   return 0;
}
