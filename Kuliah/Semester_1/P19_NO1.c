#include <stdio.h>

#define SIZE 5

int main(){
    int bil[SIZE][SIZE]; //row then column

    for (int i = 0; i<SIZE; i++){
        printf("Enter row %d: ", i+1);
        for (int j = 0; j<SIZE; j++){
            scanf("%d", &bil[i][j]);//scan akan berhenti pada spasi sehingga gunakan spasi untuk input angka ke-2 dst
        }
    }

    printf("\nData yang anda masukkan: \n");//menunjukkan hasil input
    for (int k = 0; k < SIZE; k++){
        for (int l = 0; l < SIZE; l++){
            printf("%d ", bil[k][l]);
        }
        printf("\n");
    }

    int total = 0;//untuk menghitung total
    printf("\nRow totals: ");
    for (int a = 0; a < SIZE; a++){
        for (int b = 0; b < SIZE; b++){
            total+=bil[a][b];
        }
        printf("%d ", total);
        total = 0;//mereset total
    }

    printf("\nColumn totals: ");
    for (int c = 0; c < SIZE; c++){
        for (int d = 0; d < SIZE; d++){
            total += bil[d][c];
        }
        printf("%d ", total);
        total = 0;//mereset total
    }


    return 0;
}
