#pragma once
#include<iostream>
#include "TrafficParticipant.h"
#include "TrafficLight.h"

class Footpassenger : public TrafficParticipant
{
protected:
	int speed;
public:
	Footpassenger(TrafficLight*obj);
	~Footpassenger();
	void update(int color);
	bool Footpassenger::AnalysisOfTheTrafficSituation();

};

