#include <stdio.h>
#include <math.h>
int main()
{
    float a ;
    float b ;
    float c ;
    float d ;
    float x1;
    float x2;

    printf("Mencari diskriminan dari persamaan kuadrat ax^2+bx+c\n");
    printf("Masukkan nilai a: "), scanf("%f", &a);
    printf("Masukkan nilai b: "), scanf("%f", &b);
    printf("Masukkan nilai c: "), scanf("%f", &c);

    d=b*b-4*a*c;

    printf("Hasil diskriminan dari persamaan kuadrat tersebut adalah: %f\n", d);

    if (d==0){

       x1 = -b/2*a;
       printf("Akar-akar realnya adalah x1=x2=%f\n", x1 );

    }
    else if (d>0){

        x1 = (-b + sqrt(d)) / 2*a;
        x2 = (-b - sqrt(d)) / 2*a;

        printf("Akar-akar realnya adalah x1=%f", x1);
        printf(" dan x2=%f\n", x2);


    }else if (d<0){
        x1 = -b / 2*a + (sqrt(-d) / 2*a) ;
        x2 = -b / 2*a - (sqrt(-d) / 2*a) ;
        printf("Akar-akar realnya adalah x1=%f i", x1);
        printf(" dan x2=%f i\n", x2);
    }
    return 0;

}
