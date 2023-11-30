#include "Product.h"


Airplane::Airplane(std::string customer, std::string type)
{
    this->customer = customer;
    this->type = type;
}

//Airplane::~Airplane(){}


void Airplane::SetWingspan(float wingspan)
{
    this->wingspan = wingspan;
}

void Airplane::setPowerplant(std::string powerplant)
{
    this->powerplant = powerplant;
}

void Airplane::setAvionics(std::string avionics)
{
    this->avionics = avionics;
}

void Airplane::setNumberSeats(int crewSeats, int passengerSeats)
{
    this->crewSeats = crewSeats;
    this->passengerSeats = passengerSeats;
}

std::string Airplane::getCustomer()
{
    return customer;
}

std::string Airplane::getType()
{
    return type;
}