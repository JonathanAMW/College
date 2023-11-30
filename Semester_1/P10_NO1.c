#include <stdio.h>

int main(){
    char kar;
    int x=1;

    printf("silakan mengetikkan apapun!\n");
    //scanf("%c", &kar);

    while(x == 1){
     scanf("%c", &kar);

     printf("%c", kar);

     if (kar=='\n'){
       break;

     }

    }
    printf("Anda telah mengetikkan Enter, program telah berhenti!\n");

    //pause system
    getchar();
    getchar();

    return 0;
}
