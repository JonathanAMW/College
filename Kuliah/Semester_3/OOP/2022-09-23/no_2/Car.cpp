#include <iostream>

#include "Car.h"

void Car::showCar()
{
    if(isIgnitionOn)
        std::cout << "Ignition is on. ";
    else
        std::cout << "Ignition is off. ";
    std::cout << "Speed is " << speed << std::endl;
    std::cout << "Car Id is " << carId << "\n";
    std::cout << "Car Mileage in Miles is " << getMileageInMiles() << "\n";
}

void Car::turnIgnitionOn()
{
    isIgnitionOn = true;
    mileageInMiles = 0;
}

void Car::turnIgnitionOff()
{
    speed = 0;
    isIgnitionOn = false;
}

void Car::setSpeed(int mph)
{
    const int STD_LIMIT = 65;
    if(isIgnitionOn)
        if (mph <= STD_LIMIT)
            speed = mph;
        else
            speed = STD_LIMIT;
    else
        std::cout << "Can't set speed - ignition is off!" << std::endl;
}

void Car::setCarId(std::string carId)
{
    this->carId = carId;
}

void Car::setMileageInMiles()
{
    this->mileageInMiles+=this->speed;
}

int Car::getMileageInMiles()
{
    return this->mileageInMiles;
}



void RaceCar::setSpeed(int mph)
{
    const int MAX_SPEED = 200;
    if(isIgnitionOn)
        if (mph <= MAX_SPEED)
            speed = mph;
        else
            speed = MAX_SPEED;
    else
        std::cout << "Can't set speed - ignition is off!" << std::endl;
}

