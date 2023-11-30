#include <iostream>
#include <vector>

#define MAX 100

typedef char KAR; //alias agar mudah diganti kedepannya

typedef struct date{ //definisi struct
  int day;
  int month;
  int year;
} DATE;

int main()
{
  /*
  int size, *dynamicarr;
  std::cout << "masukkan besar array: ", std::cin >> size;
  
  dynamicarr = new int[size]; //dynamic array

  for(int i=0; i<size; i++)
  {
    std::cout << "\nmasukkan data ke[" << i+1 << "]: ",std::cin >> dynamicarr[i];
  }


  delete[] dynamicarr; //untuk struktur ini, array harus dihapus setelah digunakan menggunakan delete[]

  //mencari size array 
  int Sizearr = *(&dynamicarr + 1) - dynamicarr; 
  std::cout << "\nsize diinput = " << Sizearr;
  //int Sizearr = sizeof(*dynamicarr/sizeof(dynamicarr[0]));
  //std::cout << "\nsize diinput = " << *dynamicarr;
  */


  // Menggunakkan std::vector untuk dynamic array
  // Note: no need to deallocate anything manually here
  size_t size;        // Size needed for array - size_t is the proper type for that
  std::cout << "masukkan besar array: ", std::cin >> size;        // Read in the size
  std::vector<int> dynamicarr(size, 0);  // Create vector of n elements initialised to 0
  // Use dynamicarr as a normal array
  // Its size can be obtained by dynamicarr.size()
  // If you need access to the underlying array (for C APIs, for example), use dynamicarr.data()

  std::cout << "besar array = " << dynamicarr.size();
  
  //print array
  for(int i=0; i<size; i++)
  {
    std::cout << "\ndata ke[" << i+1 << "] = " << dynamicarr[i];
  
  }



}