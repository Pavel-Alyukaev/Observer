#include "Footpassenger.h"
#include <Windows.h>
#include<ctime>



Footpassenger::~Footpassenger()
{
}

Footpassenger::Footpassenger()
{
	acceleration = 0;
	speed = (rand() % 5 + 2) / 3.6;
	distance = rand() % 15 + 5;
}

Footpassenger::Footpassenger(TrafficLight*obj)
{
	acceleration = 0;
	speed = (rand() % 5 + 2) / 3.6;
	distance = rand() % 15 + 5;
	obj->attach(this);
}
void Footpassenger::update(int color)
{
	switch (color)
	{
	case 0: 
		moveGreenLight();
		std::cout << "Footpassenger " ;
		std::cout << "	speed: " << speed << ";  distance: " << distance << ";" << std::endl;
		break;
	case 1:
		moveYellowLight();
		std::cout << "Footpassenger " ;
		std::cout << "	speed: " << speed << ";  distance: " << distance << ";" << std::endl;
		break;
	case 2:  
		moveRedLight();
		std::cout << "Footpassenger ";
		std::cout << "	speed: " << speed << ";  distance: " << distance << ";" << std::endl;
		break;
	}
}

double Footpassenger::getDistance()
{
	return distance;
}
void Footpassenger::newFootpassenger()
{
	acceleration = 0;
	speed = (rand() % 5 + 2) / 3.6;
	distance = rand() % 15 + 5;
}
void Footpassenger::moveRedLight()
{
	if (speed == 0)speed = 5 / 3.6;
	distance -= speed;
}
void Footpassenger::moveYellowLight()
{
	if (distance < 2 && distance >0.5) speed = 0;
	distance -= speed;
}
void Footpassenger::moveGreenLight()
{
	if (speed != 0)
	{
		if (distance < 2 && distance >0) speed = 0;
		distance -= speed;
	}
}