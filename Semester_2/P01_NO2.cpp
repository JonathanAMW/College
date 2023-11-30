#include <iostream>

//mendefinisikan struct
struct date{
      int day, month, year;

};

int main(){
      //mendefinisikan variable struct
      struct date today;
      struct date tomorrow;
      //atau
      typedef struct date MYDATE; //MYDATE adalah alias
      int error=0;

      today.day=16;
      today.month=8;
      today.year=2016;

      //mengambil input elemen struct
      std::cout << "Masukkan tanggal hari ini (DD/MM/YY) dengan '/' adalah spasi: ";
      std::cin >> today.day >> today.month >> today.year;

      if(today.month<=7){//sebelum agustus
            if(today.month%2==0){//bulan genap
                  if(today.month == 2){//bulan februari
                        if(today.year%4==0 && today.day+1==30){//jika bulan kabisat dan merupakan akhir bulan
                              tomorrow.month=today.month+1;
                              tomorrow.day=1;
                              tomorrow.year=today.year;

                        }else if(today.day+1==29){//jika bukan bulan kabisat dan merupakan akhir bulan
                              tomorrow.month=today.month+1;
                              tomorrow.day=1;
                              tomorrow.year=today.year;

                        }else if(today.day>=1 && today.day<=28){//jika bukan keduanya
                              tomorrow.month=today.month;
                              tomorrow.day=today.day+1;
                              tomorrow.year=today.year;
                        
                        }else 
                              error++;

                  }else //bukan bulan februari
                        if(today.day+1==31){ //jika akhir bulan
                              tomorrow.month=today.month+1;
                              tomorrow.day=1;
                              tomorrow.year=today.year;
                              
                        }else if(today.day>=1 && today.day <=30){//bukan akhir bulan
                              tomorrow.month=today.month;
                              tomorrow.day=today.day+1;
                              tomorrow.year=today.year;
                        
                        }else 
                              error++;

            }else //bulan ganjil
                  if(today.day+1==32){ //jika akhir bulan
                              tomorrow.month=today.month+1;
                              tomorrow.day=1;
                              tomorrow.year=today.year;
                              
                        }else if(today.day>=1 && today.day <=31){//bukan akhir bulan
                              tomorrow.month=today.month;
                              tomorrow.day=today.day+1;
                              tomorrow.year=today.year;
                        
                        }else 
                              error++;


      } else if (today.month>7 && today.month <= 12){
            if(today.month%2==0){//bulan genap
                  if(today.month == 12 && today.day+1==32){//bulan desember dan akhir bulan/tahun
                        tomorrow.month=1;
                        tomorrow.day=1;
                        tomorrow.year=today.year+1;

                  }else if(today.day+1==32){ //bukan bulan desember tetapi akhir bulan 
                        tomorrow.month=today.month+1;
                        tomorrow.day=1;
                        tomorrow.year=today.year;
                              
                  }else if(today.day>=1 && today.day<=31){//bukan akhir bulan
                        tomorrow.month=today.month;
                        tomorrow.day=today.day+1;
                        tomorrow.year=today.year;

                  }else
                        error++;

            }else //bulan ganjil
                  if(today.day+1==31){ //jika akhir bulan
                              tomorrow.month=today.month+1;
                              tomorrow.day=1;
                              tomorrow.year=today.year;
                              
                        }else if(today.day>=1 && today.day <=30){//bukan akhir bulan
                              tomorrow.month=today.month;
                              tomorrow.day=today.day+1;
                              tomorrow.year=today.year;

                        }else
                              error++;

      }

      if(error!=0){
            std::cout << "Tanggal tersebut tidak ada";
      }else
            std::cout << "Besok adalah: " << tomorrow.day << "-" << tomorrow.month << "-" << tomorrow.year;

}


