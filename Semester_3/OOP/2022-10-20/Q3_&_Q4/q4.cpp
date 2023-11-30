#include <iostream>
#include <cmath>

#define PI M_PI

class Shape
{
protected:
    float Area;

public:
    virtual void Calculate_Area() = 0;

    Shape()
    {
        Area = 0;
    }

    void Display()
    {
        std::cout << "Area = " << Area << "\n";
    }
};

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float radius)
    {
        this->radius = radius; 
    }
    
    void Display()
    {
        std::cout << "radius = " << radius << "\n";
    }

    void Calculate_Area()
    {
        Area = PI * pow(radius, 2);
    }
};

class Rectangle : public Shape
{
private:
    float Length;
    float Breadth;

public:
    Rectangle(float Length, float Breadth)
    {
        this->Length = Length;
        this->Breadth = Breadth;
    }
    
    void Display()
    {
        std::cout << "Length = " << Length << "\n";
        std::cout << "Breadth = " << Breadth << "\n";
    }

    void Calculate_Area()
    {
        Area = Length*Breadth;
    }
};


int main(int argc, const char *argv[])
{
    Shape *p;
    Circle C1(5);
    Rectangle R1(4,6);

    p=&C1;
    p->Calculate_Area();
    p->Display();
    p=&R1;
    p->Calculate_Area();
    p->Display();

    return 0;
}