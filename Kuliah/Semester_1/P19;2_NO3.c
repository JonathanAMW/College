#include <stdio.h>
#include <ctype.h>

#define SIZE 3
#define true (1==1)
#define false (1==0)

const char ar1[SIZE];
const char ar2[SIZE];

int equalsIgnoreCase(const char[], int, const char[], int);

int equalsIgnoreCase(const char ar1[], int size1, const char ar2[], int size2){
    int count=0;
    for(int i=0, j=0; i<SIZE; i++, j++){

        if(toupper(ar1[i])!=toupper(ar2[j])){
            count++;
            break;
        }
        
    }

    if(count==0){
        return true;
    }else
        return false;

}

int main(){
    int size1 = sizeof(ar1)/sizeof(ar1[0]);
    int size2 = sizeof(ar2)/sizeof(ar2[0]);
    
    //meminta user input
    printf("Masukkan data array ke-1 sebanyak tiga kali!\n");//input array 1
    for(int i=0; i<SIZE; i++){
        printf("Data ke-%d: ", i+1), scanf(" %c", &ar1[i]);
    }

    printf("Masukkan data array ke-2 sebanyak tiga kali!\n");//input array 2
    for(int i=0; i<SIZE; i++){
        printf("Data ke-%d: ", i+1), scanf(" %c", &ar2[i]);
    }

    printf("\nData yang anda masukkan: \n");

    //memprint user input
    printf("Array 1: ");
    for(int i=0; i<SIZE; i++){
        printf("%2c", ar1[i]);
    }
 
    printf("\nArray 2: ");
    for(int i=0; i<SIZE; i++){
        printf("%2c", ar2[i]);
    }
    printf("\n");

    //memanggil function
    equalsIgnoreCase(ar1, size1, ar2, size2);

    //memprint hasil perbandingan
    printf("\nHasil perbandingan antara array 1 dan array 2 adalah: ");
    switch(equalsIgnoreCase(ar1, size1, ar2, size2)){
        case true:
            printf("Kedua data memiliki nilai yang sama");
            break;

        case false:
            printf("Kedua data tidak memiliki nilai yang sama");
            break;
        
        default:
            printf("error on switch!");

    }       
    
    return 0;
}
