#pragma once

#include <iostream>

class Car
{
protected:
    bool isIgnitionOn;
    int speed;
    int mileageInMiles; //jarak tempuh
    std::string carId;
public:
    void turnIgnitionOn();
    void turnIgnitionOff();
    void setSpeed(int);
    void showCar();
    void setCarId(std::string);
    void setMileageInMiles();
    int getMileageInMiles();
};

class RaceCar: public Car
{
public:
    void setSpeed(int mph);
};