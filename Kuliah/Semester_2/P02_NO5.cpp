#include<iostream>

typedef struct bilangan_kompleks{
  int variabel;
  int imajiner;
}COMPLEX;

//Prosedur adalah fungsi yang tidak mengembalikan nilai yaitu void.
void penjumlahan(COMPLEX bil1, COMPLEX bil2){
  int hasil1, hasil2;
  //menghitung angka
  hasil1 = bil1.variabel + bil2.variabel;
  hasil2 = bil1.imajiner + bil2.imajiner;
  std::cout << "Hasil dari ";
  //memprint pers. 1
  std::cout << "(" << bil1.variabel << "+" << bil1.imajiner << "i)" << " + "<< "(" << bil2.variabel << "+" << bil2.imajiner << "i)" << " = "; 
  //memprint pers. 2
  std::cout << "(" << bil1.variabel << "+" << bil2.variabel << ")" << " + " << "(" << bil1.imajiner << "+" << bil2.imajiner << ")" << "i = "; 
  //memprint hasil
  std::cout << hasil1 << " + " << hasil2 << "i" << std::endl;
}

void pengurangan(COMPLEX bil1, COMPLEX bil2){
  int hasil1, hasil2;
  //menghitung angka
  hasil1 = bil1.variabel - bil2.variabel;
  hasil2 = bil1.imajiner - bil2.imajiner;
  std::cout << "Hasil dari ";
  //memprint pers. 1
  std::cout << "(" << bil1.variabel << "+" << bil1.imajiner << "i)" << "-" << "(" << bil2.variabel << "+" << bil2.imajiner << "i)" << " = "; 
  //memprint pers. 2
  std::cout << "(" << bil1.variabel << "-" << bil2.variabel << ")" << "+" << "(" << bil1.imajiner << "-" << bil2.imajiner << ")" << "i = ";
  //memprint pers. hasil
  std::cout << hasil1 << " + " << hasil2 << "i" << std::endl;
}

void perkalian(COMPLEX bil1, COMPLEX bil2){
  int hasil1, hasil2;
  //menghitung angka
  hasil1 = bil1.variabel * bil2.variabel - bil1.imajiner * bil2.imajiner;
  hasil2 = bil1.variabel * bil2.imajiner + bil1.imajiner * bil2.variabel;
  std::cout << "Hasil dari ";
  //memprint pers. 1
  std::cout << "(" << bil1.variabel << "+" << bil1.imajiner << "i)" << "*" << "(" << bil2.variabel << "+" << bil2.imajiner << "i)" << " = "; 
  //memprint pers. 2
  std::cout << "(" << bil1.variabel << "*" << bil2.variabel << "-" << bil1.imajiner << "*" << bil2.imajiner << ")" << " + " << "(" << bil1.variabel << "*" << bil2.imajiner << "+" << bil1.imajiner << "*" << bil2.variabel << ")i = ";
  //memprint pers. hasil
  std::cout << hasil1 << " + " << hasil2 << "i" << std::endl;
}

void pembagian(COMPLEX bil1, COMPLEX bil2){
  int hasil;
  hasil = ((bil1.variabel*bil2.variabel+bil1.imajiner*bil2.imajiner) / (bil1.variabel*bil1.variabel+bil1.imajiner* bil1.imajiner)) + ((bil1.imajiner*bil2.variabel-bil1.variabel*bil2.imajiner) / (bil2.variabel*bil2.variabel+bil2.imajiner*bil2.imajiner));
  std::cout << "Hasil dari ";
  //memprint pers. 1
  std::cout << "(" << bil1.variabel << "+" << bil1.imajiner << "i)" << "/" << "(" << bil2.variabel << "+" << bil2.imajiner << "i)" << " = ";
  //memprint pers. 2
  std::cout << "[(" << bil1.variabel << "*" << bil2.variabel << "+" << bil1.imajiner << "*" << bil2.imajiner << ") / (" << bil1.variabel << "*" << bil1.variabel << "+" << bil1.imajiner << "*" << bil1.imajiner << ")) + ((" << bil1.imajiner << "*" << bil2.variabel << "-" << bil1.variabel << "*" << bil2.imajiner << ") / (" << bil2.variabel << "*" << bil2.variabel << "+" << bil2.imajiner << "*" << bil2.imajiner << ")]i = ";
  //memprint pers. hasil
  std::cout << hasil << "i" << std::endl;
}

int main(){
  std::cout << "================================================================\n";
  std::cout << "\t  MENGHITUNG BILANGAN KOMPLEKS\n";
  std::cout << "================================================================\n";
  char operasi, pilihan;
  int error_utama=1, error_cabang=1;
  //misal a=bil1.variabel. b=bil1.imajiner, c=bil2.variabel, d=bil2.imajiner
  COMPLEX bil1;
  COMPLEX bil2;

  while(error_utama!=0){
    error_utama=1, error_cabang=1;
    std::cout << "Masukkan persamaan dengan format (angka)(spasi)(angka tanpa bil imajinernya)\n";
    std::cout << "Masukkan persamaan 1: ", std::cin >> bil1.variabel >> bil1.imajiner;
    std::cout << "Masukkan persamaan 2: ", std::cin >> bil2.variabel >> bil2.imajiner;
    std::cout << "Masukkan operasi yang diinginkan(+|-|*|/): ", std::cin >> operasi;

    switch(operasi){
      case '+':
        penjumlahan(bil1, bil2);
        break;

      case '-':
        pengurangan(bil1, bil2);
        break;

      case '*':
        perkalian(bil1, bil2);
        break;

      case '/':
        pembagian(bil1, bil2);
        break;

      default:
        error_utama++;
        std::cout << "Operasi tersebut tidak ada!\n";
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