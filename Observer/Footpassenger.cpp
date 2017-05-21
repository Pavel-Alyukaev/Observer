#include "Footpassenger.h"
#include <Windows.h>
#include<ctime>



Footpassenger::~Footpassenger()
{
}

Footpassenger::Footpassenger(TrafficLight*obj)
{
	srand(time(0));
	acceleration = 0;
	speed = rand() % 7+2;
	distance = rand() % 15 + 5;
	obj->attach(this);
}
void Footpassenger::update(int color)
{
	switch (color)
	{
	case 0: speed = 0;
		std::cout << "Footpassenger stop" << std::endl;
		break;
	case 1: speed = 0;

		std::cout << "Footpassenger "<< 
			(this->AnalysisOfTheTrafficSituation()? "accelerating" : "stopping" )<< std::endl;
		break;
	case 2:  speed = 5;
		std::cout << "Footpassenger go" << std::endl;
		break;
	}
}

bool Footpassenger::AnalysisOfTheTrafficSituation()
{
	return (distance<5)? true:false;
}
