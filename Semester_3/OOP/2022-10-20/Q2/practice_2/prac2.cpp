#include <iostream>

using namespace std;

class shape
{
public:
    virtual void draw() = 0; //draw() is a pure virtual function
};

class circle : public shape
{
public:
    void draw()
    {
        cout << "drawing circle...\n";
    }
};

class rectangle : public shape
{
public:
    void draw()
    {
        cout << "drawing rectangle...\n";
    }
};


int main()
{
    circle c;
    rectangle r;

    c.draw();
    r.draw();

    return 0;
}