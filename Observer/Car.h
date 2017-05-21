#pragma once
#include<iostream>
#include "TrafficParticipant.h"
#include "TrafficLight.h"

class Car : public TrafficParticipant
{

public:
	Car(TrafficLight *obj);
	~Car();
	
	void update(int color);
	bool AnalysisOfTheTrafficSituation();

};