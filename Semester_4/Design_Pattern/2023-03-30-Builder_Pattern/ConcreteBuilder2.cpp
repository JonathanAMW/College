#include "ConcreteBuilder2.h"

FighterJet::FighterJet(std::string customer)
{
    this->customer = customer;
    this->type = "F-35 Lightning IT";
}

//FighterJet::~FighterJet(){}


void FighterJet::buildWings()
{
    airplane->SetWingspan(35.0f);
}

void FighterJet::buildPowerplant()
{
    airplane->setPowerplant("dual thrust vectoring");
}

void FighterJet::buildAvionics()
{
    airplane->setAvionics("military");
}

void FighterJet::buildSeats()
{
    airplane->setNumberSeats(1,0);
}