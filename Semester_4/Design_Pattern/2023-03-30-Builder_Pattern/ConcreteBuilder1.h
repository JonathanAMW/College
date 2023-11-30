#pragma once
#include <iostream>
#include "AbstractBuilder.h"

class CropDuster : public AirplaneBuilder
{
public:
    CropDuster(std::string);
   // ~CropDuster();

    void buildWings();
    void buildPowerplant();
    void buildAvionics();
    void buildSeats();
};


