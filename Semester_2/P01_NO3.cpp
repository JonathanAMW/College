#include <iostream>
#include <string>
#include <iomanip>

#define SIZE 3

//mendefinisikan struct
struct sale{
      char kode[SIZE];
      std::string jenis[SIZE];
      int harga[SIZE];
};

void display(struct sale f_chicken){
      std::cout<<"Kode"<<std::setw(10)<<"Jenis"<<std::setw(10)<<"Harga\n";
      for(int i=0; i<SIZE; i++){
            std::cout<<f_chicken.kode[i]<<std::setw(12)<<f_chicken.jenis[i]<<std::setw(10)<<"Rp"<<f_chicken.harga[i]<<",00";
            std::cout<<"\n";
      }
}

int main(){
      char buy, decision, final;
      int amount=0, total=0, pajak;
      struct sale f_chicken = {{'D', 'P', 'S'}, {"Dada", "Paha", "Sayap"}, {5000,4000,3000}};
      
      display(f_chicken);

      while (final != 't'){
            pilihan:
            std::cout<<"Masukkan pesanan anda menggunakan kode barang: ", std::cin>>buy;
            std::cout<<"Berapa banyak?: ", std::cin>>amount;

            if(buy==f_chicken.kode[0]){
                  total+=f_chicken.harga[0]*amount;

            }else if(buy==f_chicken.kode[1]){
                  total+=f_chicken.harga[1]*amount;
                  
            }else if(buy==f_chicken.kode[2]){
                  total+=f_chicken.harga[2]*amount;

            }else{
                  std::cout << "Barang tersebut tidak ada\n";
                  goto pilihan;
            }
            
            std::cout<<"Apakah anda yakin? (y/t): ", std::cin>>decision;

            ulangi:
            switch(decision){
                  case 't':
                        goto pilihan;
                        break;
                  
                  case 'y':
                        break;
                  
                  default:
                        std::cout<<"tidak dipahami\n";
                        goto ulangi;
            }


            repeat:
            std::cout<<"Ada lagi? (y/t): ", std::cin>>final;
            switch(final){
                  case 'y':
                        goto pilihan;
                        break;

                  case 't':
                        break;
                  
                  default:
                        std::cout<<"tidak dipahami";
                        goto repeat;
            }
            std::cout<<"\n";
      }
      
      pajak=total*10/100;
      total+=pajak;
      std::cout<<"Totalnya ditambah pajak 10%, yaitu Rp"<<pajak<<",00\n";
      std::cout<<"Total belanjaan anda adalah Rp"<<total<<",00\n";
      std::cout<<"Terima kasih telah berbelanja disini!";

      return 0;
}


