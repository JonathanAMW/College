#include <stdio.h>

int main()
{
    //char kata[] = {'P', 'O', 'L', 'I', 'T', 'E', 'K', 'N', 'I', 'K'};
    char kata[] = "POLITEKNIK";
    char *pkata;
    
    pkata=&kata[2];

    printf("%c\n", *pkata);


    return 0;
}