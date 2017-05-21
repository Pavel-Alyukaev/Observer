#include <iostream>
#include <vector>
#include<Windows.h>

#include"Car.h"
#include"Footpassenger.h"
#include"TrafficLight.h"
#include"TrafficParticipant.h"


using namespace std;

int main()
{
	TrafficLight sbj; 
	Car car1(&sbj);
	Footpassenger footpassenger1(&sbj);
	for (int i = 0; i < 3; i++)
	{
		sbj.set_val(i);
		cout << endl;
	}
	system("pause");
}