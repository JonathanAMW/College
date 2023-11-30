#pragma once
#include <iostream>
#include "AbstractBuilder.h"

class FighterJet : public AirplaneBuilder
{
public: 
    FighterJet(std::string);
    //~FighterJet();

    void buildWings();
    void buildPowerplant();
    void buildAvionics();
    void buildSeats();
};