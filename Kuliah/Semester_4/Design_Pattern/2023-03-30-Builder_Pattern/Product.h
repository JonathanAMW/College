#pragma once
#include <iostream>

class Airplane
{
private:
    std::string type;
    float wingspan;
    std::string powerplant;
    int crewSeats;
    int passengerSeats;
    std::string avionics;
    std::string customer;

public:
    //~Airplane();
    
    Airplane(std::string, std::string);
    void SetWingspan(float);
    void setPowerplant(std::string);
    void setAvionics(std::string);
    void setNumberSeats(int, int);
    std::string getCustomer(); 
    std::string getType();
     
};




