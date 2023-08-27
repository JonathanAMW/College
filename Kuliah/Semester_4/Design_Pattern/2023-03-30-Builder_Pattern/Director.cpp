#include "Director.h"

void AerospaceEngineer::setAirplaneBuilder(AirplaneBuilder *ab)
{
    airplaneBuilder = ab;
}

//AerospaceEngineer::~AerospaceEngineer(){}

Airplane *AerospaceEngineer::getAirplane()
{
    return airplaneBuilder->getAirplane();
}

void AerospaceEngineer::constructAirplane()
{
    airplaneBuilder->createNewAirplane();
    airplaneBuilder->buildWings();
    airplaneBuilder->buildPowerplant();
    airplaneBuilder->buildAvionics();
    airplaneBuilder->buildSeats();
}