#include "TrafficLight.h"
#include<iostream>
#include <list>     // подключаем заголовок списка
#include <iterator> // заголовок итераторов


TrafficLight::TrafficLight()
{
}


TrafficLight::~TrafficLight()
{
}

void TrafficLight::attach(TrafficParticipant *obs)
{
	t_participants.push_back(obs);
}
 
void TrafficLight::set_val(int value)
{
	color = value;
	printColor();
	notify();
}

void TrafficLight::notify()
{
	for (auto &i : t_participants)
		 i->update(color);
}

void TrafficLight::del(TrafficParticipant *obs)
{
	t_participants.remove(obs);
}

void TrafficLight::printColor()
{
	std::cout << "Traffic light color: ";
	switch (color)
	{
	case 0:	std::cout << "GREEN" << std::endl;
		break;
	case 1:	std::cout << "YELLOW" << std::endl;
		break;
	case 2:	std::cout << "RED" << std::endl;
		break;

	}
}