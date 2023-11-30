#include <iostream>

#define SIZE 10

typedef struct polinom{
  std::string kode;
  std::string operasi; 
  int angka[SIZE];
} POLI;


void tampil(POLI *P1, POLI *P2, POLI *P3){ //menampilkan data
  std::cout << "1.\t\t" << "P1 = " << (*P1).operasi << "\n";
  std::cout << "2.\t\t" << "P2 = " << (*P2).operasi << "\n";
  std::cout << "3.\t\t" << "P3 = " << (*P3).operasi;
}

void tambah(POLI p1, POLI p2){//penjumlahan
  std::cout << "Hasil dari " << p1.kode << " + " << p2.kode << " = ";
  int hasil; 
  for(int i=SIZE-1; i>=0; i--){
    hasil = p1.angka[i] + p2.angka[i];
    for(int j=0; j<1; j++){
      if(p1.angka[i]==0 && p2.angka[i]==0){//jika array pada indeks sedang kosong
        continue;
      }else{
        if(hasil!=0 && i==0){//angka terakhir dari hasil operasi
          std::cout << abs(hasil) << "\n";
        }else if(hasil!=0){//jika hasil tidak nol
          std::cout << hasil << "x^" << i << " + ";
        }
      }
    }
    hasil=0;
  }
}

void kurang(POLI p1, POLI p2){//pengurangan
  std::cout << "Hasil dari " << p1.kode << " - " << p2.kode << " = ";
  int hasil; 
  for(int i=SIZE-1; i>=0; i--){
    hasil = p1.angka[i] - p2.angka[i];
    for(int j=0; j<1; j++){
      if(p1.angka[i]==0 && p2.angka[i]==0){//jika array pada indeks sedang kosong
        continue;
      }else{
        if(i==SIZE-1){
          std::cout << hasil << "x" << "^" << i;
        }else if(hasil!=0 && i==0){//angka terakhir dari hasil operasi
          if(hasil<0){//jika hasil negatif
            std::cout << " - " << abs(hasil) << "\n";
          }else if(hasil>0){//jika hasil positif
            std::cout << " + " << abs(hasil) << "\n";
          }
        }else if(hasil!=0){//jika hasil tidak nol
          if(hasil<0){//jika hasil negatif
            std::cout << " - " << abs(hasil) << "x^" << i;
          }else if(hasil>0){//jika hasil positif
            std::cout << " + " << abs(hasil) << "x^" << i;
          }
        }
      }
    }
    hasil=0;
  }
}

//belum bisa apabila minus
void kali(POLI p1, POLI p2){//perkalian
  std::cout << "Hasil dari " << p1.kode << " * " << p2.kode << " = ";
  int hasil[SIZE*10]={};//array kosong berisi elemen 0 semua
  for(int i=SIZE-1; i>=0; i--){
    for(int j=SIZE-1; j>=0; j--){
      hasil[i+j] += p1.angka[i]*p2.angka[j];
    }
  }
  for (int i=SIZE*10-1; i>=0; i--){//hasil diprint
    if(i==0){//jika indeks terakhir
      std::cout << hasil[i];
    }else if (hasil[i] != 0){//jika elemen indeks memiliki nilai
      std::cout << hasil[i] << "x^" << i << " + ";
    }else
      continue;
  }
}

//belum bisa apabila minus
void turunan(POLI p1){
  std::cout << "Hasil dari " << p1.kode << "'" << " = ";
  int hasil[SIZE]={}; //array kosong berisi elemen 0 semua
  for (int i=SIZE-1; i>=0; i--){
    if(i-1<0){
      continue;
    }else
      hasil[i-1]=p1.angka[i]*i;
  }
  for (int i=SIZE-1; i>=0; i--){//hasil diprint
    if(i==0){//jika indeks terakhir
      std::cout << hasil[i];
    }else if (hasil[i] != 0){//jika elemen indeks memiliki nilai
      std::cout << hasil[i] << "x^" << i << " + ";
    }else
      continue;
  }
}

int main(){
  int error_utama=1, error_cabang=1, pilihan1, pilihan2;
  char operasi, pilihan;
  POLI p1, p2; //struct temporary
  
  POLI P1 = {{"P1"}, {"6x^8 + 8x^7 + 5x^5 + x^3 + 15"}, {15, 0, 0, 1, 0, 5, 0, 8, 6, 0}};
  POLI P2 = {{"P2"}, {"3x^9 + 4x^7 + 3x^4 + 2x^3 + 2x^2 + 10 "}, {10, 0, 2, 2, 3, 0, 0, 4, 0, 3}};
  POLI P3 = {{"P3"}, {"x^2 + 5"}, {5, 0, 1, 0, 0, 0, 0, 0, 0, 0}};

  //rumus mencari length apabila diperlukan
  //int SizeP1 = *(&PoliP1 + 1) - P1.data; atau --> int arrSize = sizeof(P1.data)/sizeof(P1.data[0]);

  std::cout << "================================================================\n";
  std::cout << "\t  MENGHITUNG POLINOMIAL DARI DATA YANG ADA\n";
  std::cout << "================================================================\n";

  tampil(&P1, &P2, &P3); 

  while(error_utama!=0){
    error_utama=1;
    error_cabang=1;
    std::cout << "\n";
    std::cout << "Masukkan persamaan yang diinginkan dengan format(nomor) (+/-/*/t) (nomor, tidak perlu diisi apabila operasi turunan): \n";
    std::cout << "Masukkan pilihan 1: ", std::cin >> pilihan1; 
    std::cout << "Masukkan operasi  : ", std::cin >> operasi;
    if(operasi != 't'){
      std::cout << "Masukkan pilihan 2: ",std::cin >> pilihan2;
    }

    switch(pilihan1){
      case 1:
        p1 = P1;
        break;

      case 2:
        p1 = P2;
        break;

      case 3:
        p1 = P3;
        break;

      default:
        std::cout << "Pilihan pertama tersebut tidak ada!\n";
        error_utama++;
        break;
    }

    if (operasi != 't'){ //jika operasi bukan merupakan turunan
      switch(pilihan2){
        case 1:
          p2 = P1;
          break;

        case 2:
          p2 = P2;
          break;

        case 3:
          p2 = P3;
          break;

        default:
          std::cout << "Pilihan kedua tersebut tidak ada!\n";
          error_utama++;
          break;
      }
    }
    
    switch (operasi){
      case '+':
        tambah(p1, p2);
        break;

      case '-':
        kurang(p1, p2);
        break;

      case '*':
        kali(p1, p2);
        break;

      case 't':
        turunan(p1);
        break;

      default:
        std::cout << "Operasi tersebut tidak ada!\n";
        error_utama++;
        break;
    }

    if(error_utama==1){
      while(error_cabang!=0){
        std::cout << "\nAda lagi?(y/t): ", std::cin >> pilihan;
        switch (pilihan){
          case 'y': //keluar dari loop ini saja
            error_cabang=0;
            break;
          case 't': //keluar dari semua loop
            error_cabang--;
            error_utama=0; 
            break;
          default: //
            std::cout << "Respon tersebut tidak ada!\n";
        }
      }
    }
  }

  std::cout << "================================================================\n";
  std::cout << "\t  TERIMA KASIH DAN MOHON MAAF ATAS BUG\n";
  std::cout << "================================================================\n";
  
  return 0;
}