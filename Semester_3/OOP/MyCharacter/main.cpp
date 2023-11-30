//main
#include <iostream>
#include <ctime>

#include "MyCharacters.h"

int main()
{
	srand((unsigned) time(NULL)); //membuat random 

	//alien 1
	std::cout << "Creating a new Alien" << std::endl;
	C_Alien A001;
	A001.setColor(6);
	A001.setAge(100);
	A001.setLegs(12);
	A001.setEyes(10);
    std::cout << "A new Alien has been created" << std::endl;
	
    std::cout << std::endl; //spasi

	//alien 2
	std::cout << "Creating a new Alien" << std::endl;
	C_Alien A002;
	A002.setColor(6);
	A002.setAge(100);
	A002.setLegs(12);
	A002.setEyes(10);
    std::cout << "A new Alien has been created" << std::endl;

	std::cout << std::endl;


	std::cout << " First Alien information:" << std::endl;
	A001.DisplayAlien();
	
	std::cout << std::endl;

	std::cout << " Second Alien information:" << std::endl;
	A002.DisplayAlien();

}