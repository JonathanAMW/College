#include <iostream>
#include "FractionClass.h"

int main()
{
    C_Fraction fraction0; //cara memanggil tanpa menggunakan argument
    C_Fraction fraction1(2,6);
    C_Fraction fraction2(2,0);
    C_Fraction fraction3(3, 10, 2);
    C_Fraction fraction4(0, 2, 4);

    return 0;
}