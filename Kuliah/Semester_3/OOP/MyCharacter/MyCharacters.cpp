//method 
#include <iostream>
#include <ctime>

#include "MyCharacters.h"

std::string C_Alien::getColor()
{
	return color;
}

void C_Alien::setColor(int new_color)
{
    colors = rand() % new_color;

	switch (colors)
    {
        case 0:
            color = "black"; break;
        case 1:
            color = "green"; break;
        case 2:
            color = "yellow"; break;
        case 3:
            color = "red"; break;
        case 4:
            color = "blue"; break;
        case 5:
            color = "brown"; break;

        default:
            color = "kode warna melewati batas"; break;
    }
}

int C_Alien::getAge()
{
	return age;
}

void C_Alien::setAge(int new_age)
{
	age = rand() % new_age;
}

int C_Alien::getLegs()
{
	return legs;
}

void C_Alien::setLegs(int new_legs)
{
	legs = rand() % new_legs;

}

int C_Alien::getEyes()
{
	return eyes;
}

void C_Alien::setEyes(int new_eyes)
{
	eyes = rand() % new_eyes;
}

void C_Alien::DisplayAlien()
{
	std::cout << "Age: " << getAge() << std::endl;
	std::cout << "Legs: " << getLegs() << std::endl;
	std::cout << "Eyes: " << getEyes() << std::endl;
	std::cout << "Color: " << getColor() << std::endl;
}
