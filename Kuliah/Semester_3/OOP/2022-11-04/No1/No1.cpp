#include <iostream>
#include <cmath>


template <class T>
double circleArea(T radius)
{
    double area = 3.14 * sqrt(radius);

    return area;
}


int main()
{ 
    std::cout << "first circle area: " << circleArea(15) << std::endl; //using integer
    std::cout << "second circle area: " << circleArea(25.6) << std::endl; //using doublel
}
