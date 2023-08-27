#include <stdio.h>
#define SIZE 3


int swap(int[][SIZE], int, int, int);

int swap(int M[][SIZE], int i, int j, int ordo){
    //akan tersisa satu baris kosong dan tidak bisa pakai array 1 dimensi karena berbentuk kolom
    int temp[SIZE-1][SIZE];
    //dikurangi agar pas sesuai indek array
    i--;
    j--;
    
    for(int a=ordo-1; a>=0; a--){
        temp[0][a]=M[i][a];
    }

    for(int a=ordo-1; a>=0; a--){
        M[i][a]=M[j][a];
    }

    for(int a=ordo-1; a>=0; a--){
        M[j][a]=temp[0][a];
    }


    return M;
}



int main(){
    int M[SIZE][SIZE], i, j, ordo=SIZE;

    printf("Masukkan data array\n");//meminta input per baris
    for(int a=0; a<ordo; a++){
        for(int b=0; b<1; b++){
            printf("Masukkan baris ke-%d: ", a+1), scanf("%d %d %d", &M[a][b], &M[a][b+1], &M[a][b+2]);
        }
    }

    printf("\nData yang anda masukkan:\n");//memprint input
    for(int a=0; a<ordo; a++){
        for(int b=0; b<ordo; b++){
            printf("%3d", M[a][b]);
        }
        printf("\n");
    }

    printf("\nBaris yang akan ditukar adalah: "), scanf(" %d %d", &i, &j);

    M[SIZE][SIZE]=swap(M, i, j, ordo);

    printf("\n");
    printf("\nArray setelah ditukar adalah: \n");
    for(int a=0; a<ordo; a++){
        for(int b=0; b<ordo; b++){
            printf("%3d", M[a][b]);
        }
        printf("\n");
    }

    return 0;
}

