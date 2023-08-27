//stdio.h adalah library standart dari bahasa c 
#include <stdio.h>
#define baris 5
#define kolom 3

int main(){
    int array[kolom][baris]={
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };

    int i, j;
    for(i=0; i<kolom; i++){
        for(j=0; j<baris; j++){
            printf("%d ", array[i][j]);
            
        }

        printf("\n");
    }

    return 0;
}