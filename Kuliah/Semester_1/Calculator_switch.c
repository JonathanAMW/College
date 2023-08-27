#include <stdio.h>

int main(){

    int VALID_OPERATOR = 1; //VALID_OPERATOR DIINISIALISASI DG LOGIKA 1
    char OPERATOR;
    float NUMBER1, NUMBER2, RESULT;

    printf("MASUKKAN 2 BUAH BILANGAN & SEBUAH OPERATOR DENGAN FORMAT : NUMBER1 OPERATOR NUMBER2\n");
    scanf("%f %c %f", &NUMBER1, &OPERATOR, &NUMBER2);

    switch(OPERATOR){
        case '*':
            RESULT = NUMBER1 * NUMBER2;
            break;

        case '/':
            RESULT = NUMBER1 / NUMBER2;
            break;

        case '+':
            RESULT = NUMBER1 + NUMBER2;
            break;

        case '-':
            RESULT = NUMBER1 - NUMBER2;
            break;

    default:
        VALID_OPERATOR = 0;
    }
    switch(VALID_OPERATOR){
    case 1:
        printf("\n%g %c %g IS %g\n", NUMBER1, OPERATOR, NUMBER2, RESULT );
        break;

    default:
        printf("INVALID OPERATOR!\n");

    }


    return 0;
}


