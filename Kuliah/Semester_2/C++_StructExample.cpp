#include <iostream>

// definisi struct
typedef struct date{
  int day;
  int month;
  int year;
} DATE;

void tampil(int,int,int);  // pass by value
void tampil2(int*,int*,int*); //pass by ref
void tampil3(DATE); // pass by value, parameter struct
void tampil4(DATE *); // pass by ref, parameter struct

int main() {
  // variable struct
  DATE today;

  today.day = 22;
  today.month = 2;
  today.year = 2022;

  tampil(today.day, today.month, today.year);
  tampil2(&today.day, &today.month, &today.year);
  tampil3(today);
  tampil4(&today);
  
  tampil3(today);
}

void tampil(int day,int month,int year){
  std::cout << "Tanggal:" << day << "-" << month << "-" << year << std::endl;
}

void tampil2(int *day,int *month, int *year){
  std::cout << "Tanggal:" << *day << "-" << *month << "-" << *year << std::endl;
}

void tampil3(DATE date){
  std::cout << "Tanggal:" << date.day << "-" << date.month << "-" << date.year << std::endl;
}

void tampil4(DATE *date){
  std::cout << "Tanggal:" << (*date).day << "-" << (*date).month << "-" << (*date).year << std::endl;
  
  (*date).day = 21;
  (*date).month = 2;
  (*date).year = 2022;
}