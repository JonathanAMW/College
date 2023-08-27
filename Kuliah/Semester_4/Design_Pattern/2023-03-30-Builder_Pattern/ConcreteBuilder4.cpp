#include "ConcreteBuilder4.h"

Airliner::Airliner(std::string customer)
{
    this->customer = customer;
    this->type = "787 Dreamliner";
}

//Airliner::~Airliner(){}

void Airliner::buildWings()
{
    airplane->SetWingspan(197.0f);
}

void Airliner::buildPowerplant()
{
    airplane->setPowerplant("dual turbofan");
}

void Airliner::buildAvionics() 
{
    airplane->setAvionics("commercial");
}

void Airliner::buildSeats()
{
    airplane->setNumberSeats(8,289);
}