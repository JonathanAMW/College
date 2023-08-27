//stdio.h adalah library standart untuk c
#include <stdio.h> 

int main() {
    //latihan no 1
    char letters [10];

    //latihan no 2
    letters[3]='Z';

    //assignment
    for(int i=0; i<10; i++){
        if(i==3){
            continue;
        }else
            letters[i]='X';
    }
    
    //print
    for(int j=0; j<10; j++){
        printf("%c ", letters[j]);
    }
   
   
    return 0;
}