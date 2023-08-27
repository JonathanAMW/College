#include "AbstractBuilder.h"

//Airplane::~Airplane(){}

Airplane *AirplaneBuilder::getAirplane()
{
    return airplane;
}

void AirplaneBuilder::createNewAirplane()
{
    airplane = new Airplane(customer, type);
}
