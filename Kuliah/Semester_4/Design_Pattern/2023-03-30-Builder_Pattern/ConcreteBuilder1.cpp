#include "ConcreteBuilder1.h"


CropDuster::CropDuster(std::string customer)
{
    this->customer = customer;
    this->type = "Crop Duster v3.4";
}

//CropDuster::~CropDuster(){}

void CropDuster::buildWings()
{
    airplane->SetWingspan(9.0f);
}
void CropDuster::buildPowerplant()
{
    airplane->setPowerplant("single piston");
}

void CropDuster::buildAvionics() { }

void CropDuster::buildSeats()
{
    airplane->setNumberSeats(1,1);
}