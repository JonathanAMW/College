#include <stdio.h>

int main() {
  char pilihan;
  int total=0, angka, cek=0, maks=0, min=0; 
  float n, rata=0;

  while (pilihan == 'y' || pilihan != 't'){
    //cek adalah int, sementara rata adalah float. hal ini menyebabkan rata akan gagal menunjukkan desimal pada rata-rata
    //oleh karena itu, float n dibuat sebagai copy-an dalam tipe data yang berbeda.
    cek++;
    n=cek;

    printf("\nMasukkan bilangan ke-%d : ", cek), scanf("%d", &angka);

    total = total+angka;
    rata = total/n;

    //awalnya maks dan min dijadikan 0 agar dapat menyesuaikan input user lewat process ini
    // hal ini agar program dapat memilah apabila input pertama misalnya 5, sementara input berikutnya lebih besar dan lebih kecil dari 5
    if (maks==0 && min==0){
      maks=angka;
      min=angka;
      //untuk merubah nilai maks/min menjadi angka, haruslah maks=angka dan bukan angka=maks
      //hal ini mungkin karena vaariabel yang ditulis pertamalah yang akan dirubah 
    } else if (angka >= maks){
      maks=angka;
    } else if (angka <= min){
      min=angka;
    } else
      continue;

    printf("Mau memasukkan data lagi [y/t] ? ");
    getchar();
    pilihan=getchar();

  }
  printf("\nTotal bilangan = %d", total);
  printf("\nBilangan minimum= %d", min);
  printf("\nBilangan maksimum= %d", maks);
  printf("\nRata-rata bilangan = %f", rata);

  //ini hanyalah untuk men-pause console command dari menutup sebelum dapat terlihat outputnya
  //kadang-kadang, fungsi ini diperlukan lebih dari 1 agar dapat ter-pause
  getchar();
  getchar();
  return 0;
}