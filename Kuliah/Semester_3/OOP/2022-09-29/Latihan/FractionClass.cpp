#include <iostream>

#include "FractionClass.h"


void C_Fraction::enterFractionValue()
{
    std::cout << "================================================";
    std::cout << "Entering Fraction Value";
    std::cout << "================================================\n";

    std::cout << "Enter the whole number value: ", std::cin >> integer;
    std::cout << "Enter the numerator value: ", std::cin >> numerator;
    do
    {
        std::cout << "Enter the denominator value: ", std::cin >> denominator;
    } 
    while(denominator == 0);

}

void C_Fraction::reduceFraction()
{
    numerator = integer * denominator + numerator;
    integer = 0;

    while(1)
    {
        int gdc = 0;
        int divider = 2;

        while(divider <= 9)
        {
            if(numerator % divider == 0 && denominator % divider == 0) gdc = divider;
            divider++;
        }
        
        if(gdc == 0) break;
        else numerator /= gdc; denominator /= gdc;
    }

    while(numerator > denominator) 
    {
        if(numerator % denominator == 0)
        {
            integer += numerator / denominator;
            numerator = 0;
            denominator = 1;
        }
        else
        {
            integer += numerator % denominator;
            numerator -= denominator; 
        }
    }
}

void C_Fraction::displayFraction()
{
    std::cout << "The reduced fraction form is "<< integer << " " << numerator << fractionSymbol << denominator << std::endl;
}

int C_Fraction::getInteger()
{
    return integer;
}

void C_Fraction::setInteger(int integer)
{
    this->integer = integer;
}

int C_Fraction::getNumerator()
{
    return numerator;
}

void C_Fraction::setNumerator(int numerator)
{
    this->numerator = numerator;
}

int C_Fraction::getDenominator()
{
    return denominator;
}

void C_Fraction::setDenominator(int denominator)
{
    this->denominator = denominator;
}

/*
//ctor
C_Fraction::C_Fraction(int numerator, int denominator) //jika user mem-pass 1 value saja, maka value paramater yang tidak dipass akan diisi dgn nilai pada parameter (default)
{
    this->integer = 0;
    this->numerator = numerator;
    this->denominator = denominator;
    if(this->denominator == 0) this->denominator = 1;
    
    reduceFraction();
    displayFraction();
}

C_Fraction::C_Fraction(int integer, int numerator, int denominator)
{
    this->integer = integer;
    this->numerator = numerator;
    this->denominator = denominator;
    if(this->denominator == 0) this->denominator = 1;

    reduceFraction();
    displayFraction();
}*/

//operator overloading
C_Fraction C_Fraction::operator+(C_Fraction fraction)
{
    C_Fraction sum;
    sum.integer = 0;
    //simple simplyfy 
    numerator = integer*denominator+numerator;
    integer = 0;
    fraction.numerator = fraction.integer*fraction.denominator+fraction.numerator;
    fraction.integer = 0;

    sum.numerator = numerator * fraction.denominator + fraction.numerator * denominator;
    sum.denominator = denominator * fraction.denominator;

    sum.reduceFraction();

    return sum;
}

C_Fraction C_Fraction::operator-(C_Fraction fraction)
{
    C_Fraction sum;
    sum.integer = 0;
    //simple simplyfy 
    numerator = integer*denominator+numerator;
    integer = 0;
    fraction.numerator = fraction.integer*fraction.denominator+fraction.numerator;
    fraction.integer = 0;

    sum.numerator = numerator * fraction.denominator - fraction.numerator * denominator;
    sum.denominator = denominator * fraction.denominator;

    sum.reduceFraction();

    return sum;
}

C_Fraction C_Fraction::operator*(C_Fraction fraction)
{
    C_Fraction sum;
    sum.integer = 0;
    //simple simplyfy 
    numerator = integer*denominator+numerator;
    integer = 0;
    fraction.numerator = fraction.integer*fraction.denominator+fraction.numerator;
    fraction.integer = 0;

    sum.numerator = numerator * fraction.numerator;
    sum.denominator = denominator * fraction.denominator;

    sum.reduceFraction();
    
    return sum;
}

C_Fraction C_Fraction::operator/(C_Fraction fraction)
{
    C_Fraction sum;
    sum.integer = 0;
    //simple simplyfy 
    numerator = integer*denominator+numerator;
    integer = 0;
    fraction.numerator = fraction.integer*fraction.denominator+fraction.numerator;
    fraction.integer = 0;


    sum.numerator = numerator * fraction.denominator;
    sum.denominator = denominator * fraction.numerator;

    sum.reduceFraction();

    return sum;
}

bool C_Fraction::operator==(C_Fraction fraction)
{
    //simple simplyfy 
    numerator = integer*denominator+numerator;
    fraction.numerator = fraction.integer*fraction.denominator+fraction.numerator;

    if(numerator == fraction.numerator) return true;
    else return false;
}

bool C_Fraction::operator>(C_Fraction fraction)
{
    //simple simplyfy 
    numerator = integer*denominator+numerator;
    fraction.numerator = fraction.integer*fraction.denominator+fraction.numerator;

    if(numerator > fraction.numerator) return true;
    else return false;
}

bool C_Fraction::operator<(C_Fraction fraction)
{
    //simple simplyfy 
    numerator = integer*denominator+numerator;
    fraction.numerator = fraction.integer*fraction.denominator+fraction.numerator;

    if(numerator < fraction.numerator) return true;
    else return false;
}


std::istream &operator>>(std::istream &input, C_Fraction &fraction)
{
    std::cout << "Nilai bilangan bulat: ";
    input >> fraction.integer;

    std::cout << "Nilai pembilang: ";
    input >> fraction.numerator;

    std::cout << "Nilai penyebut: ";
    input >> fraction.denominator;
    return input;
}

std::ostream &operator<<(std::ostream &output, const C_Fraction &fraction)
{
    output << fraction.integer << " " << fraction.numerator << fraction.fractionSymbol << fraction.denominator;
    return output;
}

