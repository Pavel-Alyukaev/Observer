#pragma once

class TrafficParticipant
{
protected:
	//int index;
	double speed, distance, acceleration;
public:
	virtual ~TrafficParticipant() {};
	virtual void update(int value) = 0;

};

