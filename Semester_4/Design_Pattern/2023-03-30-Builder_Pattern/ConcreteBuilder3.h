#pragma once
#include <iostream>
#include "AbstractBuilder.h"

class Glider : public AirplaneBuilder
{
public:
    Glider(std::string);
   // ~Glider();

    void buildWings();
    void buildPowerplant();
    void buildAvionics();
    void buildSeats();
};


