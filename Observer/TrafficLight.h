#pragma once
#include"TrafficParticipant.h"
#include<list>

class TrafficLight
{
private:
	int color;
	std::list < class TrafficParticipant * > t_participants;
public:
	TrafficLight();
	~TrafficLight();
	void attach(TrafficParticipant *participant);
	void set_val(int value);
	void notify();
	void TrafficLight::printColor();
	void TrafficLight::del(TrafficParticipant *participant);
};

