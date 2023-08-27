#include <stdio.h>

int main(){
    int i, n, nilai, max=0, min=1000, King, Peasant;
    float total=0;
    printf("Berapa banyak jumlah siswa yang ingin diinputkan: "), scanf("%d", &n);

    for (i = 1; i <= n; i++){
      printf("masukkan nilai Mahasiswa ke-%d: ", i), scanf("%d", &nilai);
      total+=nilai;

      if(nilai<min){
        min=nilai;
        Peasant=i;
      }

      if (nilai>max){
        max=nilai;
        King=i;
      }

    }
    total/=n;

    printf("Mahasiswa dengan nilai terendah adalah Mahasiswa ke-%d, dengan nilai mencapai: %d\n", Peasant, min);
    printf("Mahasiswa dengan nilai tertinggi adalah Mahasiswa ke-%d, dengan nilai mencapai: %d\n", King, max);
    printf("Nilai rata-rata dari Para Mahasiswa adalah: %.2f\n", total);

    //pause system
    getchar();
    getchar();

   return 0;
}
