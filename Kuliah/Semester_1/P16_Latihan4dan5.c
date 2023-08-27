//stdio.h adalah library standart untuk c
#include <stdio.h> 
#define baris 3
#define kolom 5

int main() {
    //latihan soal 4
    float balances[baris][kolom]={{1,5,2,4,1}, {2,5,12,5,6}, {10,4,5,1.6,1.4}}, total=0; 

    //latihan soal 5
    for(int i=0, x=baris-1; i<baris; i++, x--){
        for(int j=0, y=kolom-1; j<kolom; j++, y--){
            total+=balances[x][y];
           
        }
    }

    printf("Totalnya adalah: %.2f", total);

    
    return 0;
}