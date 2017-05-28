#pragma once
#include<iostream>
#include "TrafficParticipant.h"
#include "TrafficLight.h"

class Car : public TrafficParticipant
{
protected:
	bool seeTrafficLight;
	void moveGreenLight();
	void moveYellowLight();
	void moveRedLight();
public:
	Car::Car();
	Car(TrafficLight *obj);
	~Car();
	
	void update(int color);
	double getDistance();
	void newCar();
};