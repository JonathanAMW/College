#include <iostream>

#define MAX 300

typedef int itemtype;
typedef struct konversi{
  itemtype hasil[MAX];
  int count;
}STACK;

void inisialisasi(STACK *s)
{
  s->count=0;
}

int kosong(STACK *s)
{
	return (s->count == 0);
}

int penuh(STACK *s)
{
	return (s->count == MAX);
}

void push(STACK *s, itemtype x)
{
  if(penuh(s))
  {
    std::cout << "Stack sudah penuh!\n";
  }else
    s->hasil[s->count]=x;
    s->count++;
}

itemtype pop(STACK *s)
{
  itemtype temp;
  if(kosong(s))
  {
    std::cout << "Stack kosong, tidak bisa mengambil data";
    return ' ';
  }else
    s->count--;
    temp=s->hasil[s->count];
    return(temp);
}


int main()
{
  int input, pembagi, error_utama=0, error_cabang=0;
  char pilihan; 
  itemtype x;//x adalah sisa modulo
  STACK S;
  STACK *s = &S;

  std::cout << "================================================================\n";
  std::cout << "\t  MENGKONVERSI DESIMAL -> BINER, OKTAL, HEKSA\n";
  std::cout << "================================================================\n";
  
  std::cout << "Kode\tOperasi\n";
  std::cout << "2\tBiner\n";
  std::cout << "8\tOktal\n";
  std::cout << "16\tHeksa\n";

  inisialisasi(s);

  
  while(error_utama==0)
  {
    error_utama=1, error_cabang=0;//agar apabila tidak error berhasil keluar loop

    std::cout << "Masukkan bilangan desimal yang ingin dikonversi: ", std::cin >> input;
    std::cout << "Masukkan kode operasi yang diinginkan(2/8/16): ", std::cin >> pembagi;

    if(pembagi==2 || pembagi==8 || pembagi==16)
    {
      while(input!=0)
      {
        x=input%pembagi;
        input/=pembagi;
        push(s, x);
      }
    }else{
      error_utama=0;//supaya tidak bisa keluar loop
      std::cout << "Operasi tersebut tidak ada!\n";
    }

    if(error_utama!=0) //hanya bisa diakses apabila input sebelumnya sudah benar
    {
      std::cout << "Setelah dikonversi hasilnya = ";
      for (int i=s->count-1; i>=0; i--)
      {
        std::cout << pop(s);
      }

      while(error_cabang==0)
      {
        std::cout << "\nAda lagi?(y/t): ", std::cin >> pilihan;
        switch (pilihan)
        {
          case 'y': //keluar dari loop ini saja
            error_cabang=1;
            error_utama=0;
            break;
          case 't': //keluar dari semua loop
            error_cabang=1;
            error_utama=1; 
            break;
          default: //
            std::cout << "Respon tersebut tidak ada!\n";
        }
      }
    }
    inisialisasi(s); 
  }
  return 0;
}