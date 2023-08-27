#pragma once
#include <iostream>
#include "Product.h"

class AirplaneBuilder
{
protected:
    Airplane *airplane;
    std::string customer;
    std::string type;

public:

   // ~AirplaneBuilder();

    Airplane *getAirplane();
    void createNewAirplane();

    virtual void buildWings() = 0;
    virtual void buildPowerplant() = 0;
    virtual void buildAvionics() = 0;
    virtual void buildSeats() = 0;

};





