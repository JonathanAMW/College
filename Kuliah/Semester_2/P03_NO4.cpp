#include <iostream>
#include <stack> //fungsi untuk menggunakan fungsi stack
//anggotanya empty, size, push, pop, top

/*
void printstack(std::stack<char> STACK)
{
  while(!STACK.empty()){ //selama stack tidak kosong menggunakan "!"
    std::cout << STACK.top();
    STACK.pop();
  }
}
*/

int main()
{
  std::stack<char> STACK;
  std::stack<char> pembanding;
  std::string kalimat;
  char pilihan;
  int error=1;

  std::cout << "================================================================\n";
  std::cout << "\t MENGECEK PALINDROM MENGGUNAKAN LIBRARY STACK\n";
  std::cout << "================================================================\n";

  while(error!=0){
    error=1;
    std::cout << "Ketik Kalimat: ", std::getline(std::cin, kalimat);

    //memasukkan hasil input ke stack
    for(int i=0, j=kalimat.size()-1; i<kalimat.size(); i++, j--)
    {
      STACK.push(kalimat[i]);
      pembanding.push(kalimat[j]); //terbalik agar bisa dibandingkan
    }
    
    if(STACK==pembanding){ //mengecek palindrom
      std::cout << "Kalimat tersebut adalah palindrom" << std::endl;
    }else{
      std::cout << "Kalimat tersebut bukanlah palindrom" << std::endl;
    }

    //menghilangkan isi stack untuk operasi lanjutan
    for(int i=STACK.size()-1; i>=0; i--)
    {
      STACK.pop();
      pembanding.pop();
    }

    while(error == 1) 
    {
      std::cout << "\nAda lagi?(y/t): ", std::cin >> pilihan;
      std::cin.ignore(); //cin.ignore menghilangkan input selanjutnya, biasanya '\n'
      switch (pilihan)
      {
        case 'y': //keluar dari loop ini saja
          error=2;
          break;
        case 't': //keluar dari semua loop
          error=0; 
          break;
        default: //
          std::cout << "Respon tersebut tidak ada!\n";
      }
    }
  }

  //printstack(STACK); //meng-output stack
  //std::cout << "\n";
  return 0;
}

