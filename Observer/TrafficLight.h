#pragma once
#include <vector>
#include"TrafficParticipant.h"

class TrafficLight
{
private:
	int color;
	std::vector < class TrafficParticipant * > t_participants;
public:
	TrafficLight();
	~TrafficLight();
	void attach(TrafficParticipant *participant);
	void set_val(int value);
	void notify();
};

