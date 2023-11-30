#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(){
    int bil, move=0, error=0;
    char kar='B', array[SIZE][SIZE] = {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    };

    srand((unsigned) time(NULL));

    int startrow = rand() % 9 + 0; // int random_number = rand() % range + min; sebagai rumusnya
    int startcolumn = rand() % 9 + 0; // int random_number = rand() % range + min; sebagai rumusnya

    array[startrow][startcolumn] = 'A';

    int numb=0;//mengurangi kemungkinan huruf menabrak huruf

    ulang:
    while(kar <= 'Z'){
        
        do{
            move = rand() % 4 + 1; // int random_number = rand() % range + min; sebagai rumusnya

        }while(move==numb);

        //penentuan
        switch (move){
            case 1://bawah
                if(array[startrow+1][startcolumn]=='.' && startrow+1<=9){
                    startrow += 1;
                    array[startrow][startcolumn] = kar;
                    kar++;
                    numb=3;
                    break;


                }else if(startrow+1>9){
                    goto ulang;
                    break;


                }else 
                    error++;
                    goto error;
                    break;


                //break;

            case 2://kanan
                if (array[startrow][startcolumn+1]=='.' && startcolumn+1<=9){
                    startcolumn += 1;
                    array[startrow][startcolumn] = kar;
                    kar++;
                    numb=4;
                    break;


                }else if(startcolumn+1>9){
                    goto ulang;
                    break;


                }else
                    error++;
                    goto error;
                    break;

                //break;

            case 3://atas
                if (array[startrow-1][startcolumn] == '.' && startrow-1>=0){
                    startrow -= 1;
                    array[startrow][startcolumn] = kar;
                    kar++;
                    numb=1;
                    break;


                }else if(startrow-1<0 ){
                    goto ulang;
                    break;


                }else
                    error++;
                    goto error;
                    break;


                //break;

            case 4://kiri
                if (array[startrow][startcolumn-1]=='.' && startcolumn-1>=0){
                    startcolumn -= 1;
                    array[startrow][startcolumn] = kar;
                    kar++;
                    numb=2;
                    break;

                
                }else if(startcolumn-1<0){
                    goto ulang;
                    break;


                }else
                    error++;
                    goto error;
                    break;


                //break;

            default:
                printf("\nError in 1st switch\n");

        }

    }

    error:
    // print
    /*for (int i = 0; i < SIZE-1; i++){
        for (int j = 0; j < SIZE-1; j++){
            printf("%2c", array[i][j]);
        }
        printf("\n");
    }*/

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            printf("%2c", array[i][j]);
        }
        printf("\n");
    }

    if(error!=0){
        printf("Program berhenti karena huruf keluar dari batas atau menabrak huruf lain\n");
    }

    return 0;
}
