#include <iostream>

#define MAX 24 //sesuai jumlah kata pada materi

typedef char kar;
typedef struct
{
  kar kalimat[MAX];
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

void push(STACK *s, kar x)
{
  if(penuh(s))
  {
    std::cout << "Stack sudah penuh!\n";
  }else{ 
    s->kalimat[s->count]=x;
    s->count++;
  }
}

kar pop(STACK *s)
{
  kar temp;
  if(kosong(s))
  {
    std::cout << "Stack kosong, tidak bisa mengambil data";
    return ' ';
  }else{
    s->count--;
    temp=s->kalimat[s->count];
    return(temp);
  }
}

int main()
{
  kar x;
  STACK S; //segmentation fault apabila stack *s tidak merujuk ke siapa2
  STACK *s = &S;
  
  inisialisasi(s);

  std::cout << "Masukkan kalimat(tanpa spasi): ";

  for(int i=0; i<MAX; i++)
  {
    std::cin >> x;
    if(x == '*')
    {
      //pop(s);
      std::cout << pop(s);
    }else
      push(s, x);

  }
  
  std::cout << "\n";
  for (int i=MAX-1; i>=0; i--)
  {
    std::cout << "Isi stack ke-"<< i+1 << " = " << pop(s) << "\n";
  } 
  
  inisialisasi(s);
}