#pragma once

class TrafficParticipant
{
protected:
	int speed, distance, acceleration;
public:
	virtual void update(int value) = 0;


};

