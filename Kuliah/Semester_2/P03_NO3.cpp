#include <iostream>

#define MAX 100 //sesuai jumlah kata pada materi

typedef char kar;
typedef struct
{
  kar kata[MAX];
  int count;
} STACK;

void inisialisasi(STACK *s)
{
  s->count = 0;
}

int penuh(STACK *s)
{
  return(s->count == MAX);
}

int kosong(STACK *s)
{
  return(s->count == 0);
}

void push(STACK *s, std::string kalimat, int i)
{
  if(penuh(s))
  {
    std::cout << "Stack sudah penuh!\n";
  }else
    s->kata[s->count]=kalimat[i];
    s->count++;
}

kar pop(STACK *s)
{
  kar temp;
  if(kosong(s))
  {
    std::cout << "Stack kosong, tidak bisa mengambil data";
    return ' ';
  }else
    s->count--;
    temp=s->kata[s->count];
    return(temp);
}


int main()
{
  std::string kalimat;
  int panjang;
  int i;

  STACK S; //segmentation fault apabila stack *s tidak merujuk ke siapa2
  STACK *s = &S;

  std::cout << "================================================================\n";
  std::cout << "\t  MEMBALIKKAN KALIMAT MENGGUNAKAN STACK\n";
  std::cout << "================================================================\n";
  
  inisialisasi(s);

  std::cout << "Masukkan kalimat: ";
  std::getline(std::cin, kalimat); //(cin, variabel)
  panjang=kalimat.size(); //mengambil panjang kata yang diinput

  for(i=0; i<panjang; i++)
  {
    push(s, kalimat, i);
  }
  
  std::cout << "\n";
  std::cout << "Hasil pembalikkannya : ";

  for(i=0; i<panjang; i++)
  {
    std::cout << pop(s);
  }

  inisialisasi(s);

  return 0;
}