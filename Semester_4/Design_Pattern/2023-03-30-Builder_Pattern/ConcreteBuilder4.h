#pragma once
#include <iostream>
#include "AbstractBuilder.h"

class Airliner : public AirplaneBuilder
{
public:
    Airliner(std::string);
    //~Airliner();

    void buildWings();
    void buildPowerplant();
    void buildAvionics();
    void buildSeats();
};


