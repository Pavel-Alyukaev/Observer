#include "Car.h"
#include <Windows.h>
#include<ctime>


Car::Car()
{
	acceleration =0;
	speed = (rand() % 21 + 50) / 3.6;
	distance = rand() % 200 + 10;
	seeTrafficLight = false;
}

Car::Car(TrafficLight *obj)
{
	acceleration = 0;
	speed = (rand() % 21 + 50)/3.6;
	distance = rand() % 100 + 10;
	obj->attach(this);
	seeTrafficLight = true;
}

Car::~Car()
{
}



void Car::update(int color)
{
		switch (color)
		{
		case 0:
			
			std::cout << "Car ";
			std::cout <<"	speed: " << speed << ";  distance: " << distance << ";" << std::endl;
			moveGreenLight();
			break;
		case 1: 
			
			std::cout << "Car ";
			std::cout << "	speed: " << speed << ";  distance: " << distance << ";" << std::endl;
			moveYellowLight();
			break;
		case 2:  
			
			std::cout << "Car ";
			std::cout << "	speed: " << speed << ";  distance: " << distance << ";" << std::endl;
			moveRedLight();
			break;
		}
}


double Car::getDistance()
{
	return distance;
}
void Car::newCar()
{
	acceleration = 0;
	speed = (rand() % 21 + 50) / 3.6;
	distance = rand() % 100 + 10;
}
void Car::moveGreenLight()
{
	if (speed < 50 / 3.6)
	{
		acceleration = 5;
		speed += acceleration;
	}
	distance -= speed;
}
void Car::moveYellowLight()
{
	if (distance > 50 && distance<70)
	{
		if (speed != 0)
		{
			acceleration = (acceleration >= 5) ? speed*speed / (distance + 1) : 5;
			speed = -acceleration;
			(speed <= 0) ? speed = 0 :
				distance -= speed + acceleration / 2;
		}
	}
	else 	distance -= speed;
}
void Car::moveRedLight()
{
	if (speed != 0)
	{
		if (distance < 50)
		{
			acceleration = speed*speed / (distance + 1);
			speed = -acceleration;
			(speed <= 0) ? speed = 0 :
			distance -= speed + acceleration / 2;
		}
		else distance -= speed;
	}
}



