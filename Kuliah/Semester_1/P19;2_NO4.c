#include <stdio.h>
#define SIZE 3

//const int n=sizeof(A)/sizeof(A[0]);//mencari panjang array

void jumlahMatrik(int[][SIZE], int[][SIZE], int[][SIZE], int);
void kurangMatrik(int[][SIZE], int[][SIZE], int[][SIZE], int);


void jumlahMatrik(int A[][SIZE], int B[][SIZE], int C[][SIZE], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}

void kurangMatrik(int A[][SIZE], int B[][SIZE], int C[][SIZE], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C[i][j]=A[i][j]-B[i][j];
        }
    }
}



int main(){
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    int n=SIZE;
    char operator;

    printf("================================================================\n");
    printf("Menghitung Penjumlahan/Pengurangan Matriks 3x3\n");
    printf("================================================================\n");

    printf("\nMasukkan data matrik pertama!\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<1; j++){
            printf("Masukkan baris ke-%d: ", i+1), scanf("%d %d %d", &A[i][j], &A[i][j+1], &A[i][j+2]);

        }
    }

    printf("\nMasukkan data matrik kedua!\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<1; j++){
            printf("Masukkan baris ke-%d: ", i+1), scanf("%d %d %d", &B[i][j], &B[i][j+1], &B[i][j+2]);

        }
    }

    operasi:
    printf("\nTuliskan tanda saja (ex: + - )\n");
    printf("Operasinya?:"), scanf(" %c", &operator);

    switch(operator){
        case '+':
            jumlahMatrik(A,B,C,n);
            break;

        case '-':
            kurangMatrik(A,B,C,n);
            break;

        default:
            printf("Operator tidak ada!");
            goto operasi;

    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%3d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

