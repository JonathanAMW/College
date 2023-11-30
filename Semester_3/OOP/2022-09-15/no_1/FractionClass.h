#pragma once

#include <iostream>

class C_Fraction
{
    private:
        int integer;
        int numerator;
        int denominator;
    
    public:
        const static char fractionSymbol = '/';
        void enterFractionValue();
        void reduceFraction();
        void displayFraction();

};