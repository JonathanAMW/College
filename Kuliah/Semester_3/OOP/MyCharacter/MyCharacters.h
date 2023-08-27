#pragma once
//constructor
#include <iostream>

class C_Alien {
private:
	int colors;
	std::string color;
	int age;
	int legs;
	int eyes;

public:
    //prototype methods
	std::string getColor();
	int getAge(); //getter or accessor
	void setAge(int); //setter or mutator
	void setColor(int);
	int getLegs();
	void setLegs(int);
	int getEyes();
	void setEyes(int);
	void DisplayAlien();
};