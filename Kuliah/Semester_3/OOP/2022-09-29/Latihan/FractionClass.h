#pragma once

#include <iostream>

class C_Fraction
{
    friend std::ostream &operator<<(std::ostream &, const C_Fraction &);
    friend std::istream &operator>>(std::istream &, C_Fraction &);

    private:
        int integer;
        int numerator;
        int denominator;
    
    public:
        const static char fractionSymbol = '/'; //static berarti shared by all member of class, const berarti valuenya tidak bisa diganti
        //methods
        void enterFractionValue();
        void reduceFraction();
        void displayFraction();
        int getInteger();
        void setInteger(int);
        int getNumerator();
        void setNumerator(int);
        int getDenominator();
        void setDenominator(int);

        //ctor
        //C_Fraction(int numer = 0, int denom = 1); //jika user mem-pass 1 value saja, maka value paramater yang tidak dipass akan diisi dgn nilai pada parameter (default)
        //C_Fraction(int wholenum, int numer, int denom);
        
        //overloading operator func
        C_Fraction operator+(C_Fraction);
        C_Fraction operator-(C_Fraction);
        C_Fraction operator*(C_Fraction);
        C_Fraction operator/(C_Fraction);

        bool operator==(C_Fraction);
        bool operator>(C_Fraction);
        bool operator<(C_Fraction);
};