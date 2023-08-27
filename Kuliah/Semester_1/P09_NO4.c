#include <stdio.h>

int main(){
    char kar; //karakter
    int m=0; //jumlah karakter
    int spasi=0; 
    int kapital=0;
    int kecil=0;
    int n=0; //angka
    int simbol=0;
    int neither=0;//sedikit percobaan

    printf("Ketikkan sembarang kalimat : \n"); 
    //tidak bisa menggunakan scanf karena pembacaannya berakhir pada spasi
    while((kar=getchar()) != '\n'){
      ++m;
       if (kar==32){
          ++spasi;

        } else if (kar>=48 && kar<=57) {
          ++n;

        } else if (kar>=65 && kar<=90){
          ++kapital;

        } else if (kar>=97 && kar<=122){
          ++kecil;

        } else
          ++neither;

    }
    printf("Jumlah karakter = %d\n", m);
    printf("Jumlah spasi = %d\n", spasi);
    printf("Jumlah angka = %d\n", n);
    printf("Jumlah huruf kapital = %d\n", kapital);
    printf("Jumlah huruf kecil = %d\n", kecil);
    printf("Jumlah karakter yang tidak diketahui = %d\n", neither);

    getchar();
    getchar();

    return 0;
}
