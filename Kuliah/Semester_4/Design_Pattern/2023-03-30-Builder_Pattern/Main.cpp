#include<iostream>
#include "Director.h"
#include "AbstractBuilder.h"
#include "ConcreteBuilder1.h"
#include "ConcreteBuilder2.h"
#include "ConcreteBuilder3.h"
#include "ConcreteBuilder4.h"


int main()
{
    //instantiate director (hire the engineer)
    AerospaceEngineer *aero = new AerospaceEngineer();

    //instantiate setiap concrete builder (take order)
    AirplaneBuilder *crop = new CropDuster("Farmer Joe"); 
    AirplaneBuilder *fighter = new FighterJet("The Navy"); 
    AirplaneBuilder *glider = new Glider("Tim Rice"); 
    AirplaneBuilder *airliner = new Airliner("United Airlines"); 

    //build a cropduster
    aero->setAirplaneBuilder(crop);
    aero->constructAirplane();
    Airplane *completedCropDuster = aero->getAirplane();

    std::cout << completedCropDuster->getType() 
        << " is completed and ready for delivery to "
        << completedCropDuster->getCustomer() 
        << std::endl;

    //build a fighterjer
    aero->setAirplaneBuilder(fighter);
    aero->constructAirplane();
    Airplane *completedFighterJet = aero->getAirplane();

    std::cout << completedFighterJet->getType() 
        << " is completed and ready for delivery to "
        << completedFighterJet->getCustomer() 
        << std::endl;

    //build a glider
    aero->setAirplaneBuilder(glider);
    aero->constructAirplane();
    Airplane *completedGlider = aero->getAirplane();

    std::cout << completedGlider->getType() 
        << " is completed and ready for delivery to "
        << completedGlider->getCustomer() 
        << std::endl;


    //build a airliner
    aero->setAirplaneBuilder(airliner);
    aero->constructAirplane();
    Airplane *completedAirliner = aero->getAirplane();

    std::cout << completedAirliner->getType() 
        << " is completed and ready for delivery to "
        << completedAirliner->getCustomer() 
        << std::endl;


    delete completedCropDuster;
    delete completedFighterJet;
    delete completedGlider;
    delete completedAirliner;
    delete aero;
    delete crop;
    delete fighter;
    delete glider;
    delete airliner;


    return 0;
}