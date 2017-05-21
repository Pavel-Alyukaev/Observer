#include "TrafficLight.h"



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
	notify();
}

void TrafficLight::notify()
{
	for (int i = 0; i < t_participants.size(); ++i)
		t_participants[i]->update(color);
}