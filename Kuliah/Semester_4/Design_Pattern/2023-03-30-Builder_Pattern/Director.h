#pragma once
#include <iostream>
#include "AbstractBuilder.h"

class AerospaceEngineer
{
private:
    AirplaneBuilder* airplaneBuilder;

public:
   // ~AerospaceEngineer();

    void setAirplaneBuilder(AirplaneBuilder *ab);
    Airplane *getAirplane();
    void constructAirplane();
};