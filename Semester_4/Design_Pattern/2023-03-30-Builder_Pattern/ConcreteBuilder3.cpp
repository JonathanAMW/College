#include "ConcreteBuilder3.h"

Glider::Glider(std::string customer)
{
    this->customer = customer;
    this->type = "Glider v9.0";
}

//Glider::~Glider(){}

void Glider::buildWings()
{
    airplane->SetWingspan(57.1f);
}

void Glider::buildPowerplant() {}

void Glider::buildAvionics() {}

void Glider::buildSeats()
{
    airplane->setNumberSeats(1,0);
}