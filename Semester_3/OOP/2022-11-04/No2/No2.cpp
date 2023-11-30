#include <iostream>


template <class T>
int calcDistance(T distancePointA, T distancePointB)
{
    return distancePointA + distancePointB;
}


//class
class City
{
protected:
    std::string cityName;
    int cityDistanceFromChicago;

public:
    double operator+(City);
    void setCityName(std::string);
    std::string getCityName();
    void setCityDistanceFromChicago(int);
    int setCityDistanceFromChicago();
};

class Planet
{
protected:
    std::string planetName;
    int planetDistanceFromEarth;

public:
    double operator+(Planet);
    void setPlanetName(std::string);
    std::string getPlanetName();
    void setPlanetDistanceFromEarth(int);
    int setPlanetDistanceFromEarth();
};

//Planet
void City::setCityName(std::string cityName)
{
    this->cityName = cityName;
}

std::string City::getCityName()
{
    return this->cityName;
}

void City::setCityDistanceFromChicago(int cityDistanceFromChicago)
{
    this->cityDistanceFromChicago = cityDistanceFromChicago;
}

int City::setCityDistanceFromChicago()
{
    return this->cityDistanceFromChicago;
}

double City::operator+(City cityName)
{
    return calcDistance(cityDistanceFromChicago, cityName.cityDistanceFromChicago);
}


//Planet
double Planet::operator+(Planet planetName)
{
    return calcDistance(planetDistanceFromEarth, planetName.planetDistanceFromEarth);
}

void Planet::setPlanetName(std::string planetName)
{
    this->planetName = planetName;
}

std::string Planet::getPlanetName()
{
    return this->planetName;
}

void Planet::setPlanetDistanceFromEarth(int planetDistanceFromEarth)
{
    this->planetDistanceFromEarth = planetDistanceFromEarth;
}

int Planet::setPlanetDistanceFromEarth()
{
    return this->planetDistanceFromEarth;
}



int main(int argc, const char** argv) 
{
    int x1 = 10, x2 = 20;
    double y1 = 20.4f, y2 = 10.45;

    std::cout << "Penjumlahan Variabel\n";
    std::cout << x1 << " + " << x2 << " = " << calcDistance(x1, x2) << std::endl;
    std::cout << y1 << " + " << y2 << " = " << calcDistance(y1, y2) << std::endl;

    //City setup
    City Montgomery, Atlanta, Dover, A, B, C;
    A.setCityName("Montgomery"); A.setCityDistanceFromChicago(1061);
    B.setCityName("Atlanta"); B.setCityDistanceFromChicago(945);
    C.setCityName("Dover"); C.setCityDistanceFromChicago(1067);

    std::cout << "\nPenjumlahan Class City\n";
    std::cout << A.getCityName() << " to " << B.getCityName() << " is " << A+B << " km\n";
    std::cout << B.getCityName() << " to " << C.getCityName() << " is " << B+C << " km\n";
    std::cout << C.getCityName() << " to " << A.getCityName() << " is " << C+A << " km\n";


    //Planet setup
    Planet X, Y;
    X.setPlanetName("Mercury"); X.setPlanetDistanceFromEarth(33);
    Y.setPlanetName("Venus"); Y.setPlanetDistanceFromEarth(26);

    std::cout << "\nPenjumlahan Class Planet\n";
    std::cout << X.getPlanetName() << " to " << Y.getPlanetName() << " is " << X+Y << " million miles\n";


    return 0;
}


