#include <iostream>
#include <ctime>

#include "Car.h"

int main()
{
    const int raceTrackLength = 500;

    Car car1;
    car1.setCarId("car001");

    RaceCar raceCar1;
    raceCar1.setCarId("raceCar001");


    //starting the race
    car1.turnIgnitionOn();
    raceCar1.turnIgnitionOn();

	srand((unsigned) time(NULL)); //membuat random 

    int random;

    while(1)
    {
        if(car1.getMileageInMiles() > raceTrackLength && raceCar1.getMileageInMiles() > raceTrackLength)
        {
            if(car1.getMileageInMiles() == raceCar1.getMileageInMiles())
            {
                std::cout << "It's a draw\n";
            }
            else if (car1.getMileageInMiles() > raceCar1.getMileageInMiles())
            {
                std::cout << "The winner is: \n";
                car1.showCar();
                std::cout << "\n";
                std::cout << "The loser is: \n";
                raceCar1.showCar();
            }
            else if (car1.getMileageInMiles() < raceCar1.getMileageInMiles())
            {
                std::cout << "The winner is: \n";
                raceCar1.showCar();
                std::cout << "\n";
                std::cout << "The loser is: \n";
                car1.showCar();
            }
            break;  
        }
        else if (car1.getMileageInMiles() > raceTrackLength)
        {
            std::cout << "The winner is: \n";
            car1.showCar();
            std::cout << "\n";
            std::cout << "The loser is: \n";
            raceCar1.showCar();
            break;
        }
        else if (raceCar1.getMileageInMiles() > raceTrackLength)
        {
            std::cout << "The winner is: \n";
            raceCar1.showCar();
            std::cout << "\n";
            std::cout << "The loser is: \n";
            car1.showCar();

            break;
        }

        random = 1 + (rand() % 199);
        car1.setSpeed(random);
        car1.setMileageInMiles();
        random = 1 + (rand() % 199);
        raceCar1.setSpeed(random);
        raceCar1.setMileageInMiles();

    }
    

    return 0;
}