#include <iostream>
#include <ctime>

#include "FractionClass.h"

#define MAX 10

int main()
{
    C_Fraction fractionArr[MAX];
    
    int random;

    srand((unsigned) time(NULL)); //membuat random 
    
    for(int i=0; i<MAX; i++)
    {
        random = 1 + (rand() % 5);
        fractionArr[i].setInteger(0); //anggap pecahan tanpa integer atau wholenumber
        fractionArr[i].setNumerator(random);
        fractionArr[i].setDenominator(10);
        
        fractionArr[i].reduceFraction();
        std::cout << i+1 << " "; 
        fractionArr[i].displayFraction();
    }

    char pilihan;
    std::cout << "Pilih operasi ( + | - | * | / ): ", std::cin >> pilihan;

    C_Fraction sum;
    for(int i=0, j=MAX/2; i<MAX/2; i++, j++)
    {
        switch (pilihan)
        {
        case '+':
            sum.setInteger(0);
            sum = fractionArr[i] + fractionArr[j];
            
            std::cout << i+1 << ". " << fractionArr[i] << " + " << fractionArr[j] << " = " << sum << std::endl;

            break;

        case '-':
            if(fractionArr[i] < fractionArr[j])
            {
                sum.setInteger(0);
                sum = fractionArr[j] - fractionArr[i];
            
                std::cout << i+1 << ". " << fractionArr[j] << " - " << fractionArr[i] << " = " << sum << std::endl;

            }
            else
            {
                sum.setInteger(0);
                sum = fractionArr[i] - fractionArr[j];
                
                std::cout << i+1 << ". " << fractionArr[i] << " - " << fractionArr[j] << " = " << sum << std::endl;

            }
            break;

        case '*':
            sum.setInteger(0);
            sum = fractionArr[i] * fractionArr[j];
            
            std::cout << i+1 << ". " << fractionArr[i] << " * " << fractionArr[j] << " = " << sum << std::endl;
        
            break;

        case '/':
            sum.setInteger(0);
            sum = fractionArr[i] / fractionArr[j];
            
            std::cout << i+1 << ". " << fractionArr[i] << " / " << fractionArr[j] << " = " << sum << std::endl;

            break;

        default:
            std::cout << "gak ada!";
            break;
        }

    }

    return 0;
}