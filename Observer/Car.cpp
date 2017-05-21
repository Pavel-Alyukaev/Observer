#include "Car.h"
#include <Windows.h>
#include<ctime>



Car::Car(TrafficLight *obj)
{
	srand(time(0));
	acceleration = 0;
	speed = rand() % 21 + 50;
	distance = rand() % 100 + 10;
	obj->attach(this);
}


Car::~Car()
{
}



void Car::update(int color)
{
	switch (color)
	{
	case 0: speed = 0;
		std::cout << "Car go" << std::endl;
		break;
	case 1: speed = 0;
		std::cout << "Car " <<
			(this->AnalysisOfTheTrafficSituation() ? "accelerating" : "stopping") << std::endl;
		break;
	case 2:  speed = 5;
		std::cout << "Car stop" << std::endl;
		break;
	}
}

bool Car::AnalysisOfTheTrafficSituation()
{
	return (distance<50) ? true : false;
}