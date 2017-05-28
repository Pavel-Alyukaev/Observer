#pragma once
#include<iostream>
#include "TrafficParticipant.h"
#include "TrafficLight.h"

class Footpassenger : public TrafficParticipant
{
protected:
	void moveGreenLight();
	void moveYellowLight();
	void moveRedLight();
public:
	Footpassenger();
	Footpassenger(TrafficLight*obj);
	~Footpassenger();
	void update(int color);
	double getDistance();
	void newFootpassenger();

};


