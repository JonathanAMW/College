#include <stdio.h>


const char array[6]={'c','s','c','2','6','1'};
const char *arraylagi[6];


void reverse(const char[], int);//perlu diberi[] karena array

void reverse(const char array[], int size){
  for(int i=size-1, j=0; i>=0; i--, j++){
    arraylagi[j]=array[i]; 

  }

}

int main(){
  int size = sizeof(array)/sizeof(array[0]);

  reverse(array, size);

  for(int i=0; i<size; i++){
    printf("%c", arraylagi[i]);

  }

}
