#include <iostream>
#include <string>

using namespace std;

//class
class SalesOffice
{
    friend ostream& operator<<(ostream&, const SalesOffice&);
private:
    string officeName;
    double sales;
public:
    SalesOffice(string, double);
    double operator/(SalesOffice);
};

//methods
SalesOffice::SalesOffice(string office, double salesAmt)
{
    officeName = office;
    sales = salesAmt;
}

double SalesOffice::operator/(SalesOffice office)
{
    double ratio;
    ratio = sales / office.sales;
    return ratio;
}

ostream& operator<<(ostream& out, const SalesOffice& anOffice)
{
    out << "The " << anOffice.officeName << " Office sold $" << anOffice.sales << endl;
    return out;
}


//main funct
int main()
{
    SalesOffice north("North", 2454.88);
    SalesOffice south("South", 2830.92);
    double ratio;
    ratio = north / south;
    cout << north;
    cout << south;
    cout << "THe North Office has " << (ratio * 100) << "% of the sales of South Office" << endl;
    return 0;
}