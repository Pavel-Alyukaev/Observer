#include <iostream>
#include <vector>
#include<iterator>
#include<Windows.h>
#include<ctime>

#include"Car.h"
#include"Footpassenger.h"
#include"TrafficLight.h"
#include"TrafficParticipant.h"


using namespace std;
void timer(int ms);
int color(std::clock_t& start);
template<class T>void delPatrtisipant(vector<T>&Patrtisipant, TrafficLight& sbj);

int main()
{
	srand(time(0));
	std::clock_t start;
	TrafficLight sbj; 
	vector<Car> car(10);
	vector<Footpassenger> footpassenger(20);
	start = clock();

	
	int j = 0;
	int carCount = 0;
	int FootCount = 0;
	int i;
	while (j<100)
	{
		switch (j % 10)
		{
		case 0:sbj.attach(&footpassenger[FootCount++]);
			break;
		case 1:sbj.attach(&car[carCount++]);
			break;
		case 5:	sbj.attach(&footpassenger[FootCount++]);
			break;
		}

		if (FootCount > footpassenger.size())FootCount = 0;
		if (carCount > car.size())carCount = 0;

		delPatrtisipant(car,  sbj);
		delPatrtisipant(footpassenger,  sbj);
		cout <<  " j=" << j << endl;
		i = color(start);
		sbj.set_val(i);
		j++;
		timer(2000);
		system("cls");
	}
		
	system("pause");
}

void timer(int ms) {
	int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000;   /// новая константа 
	clock_t end_time = clock() + ms * CLOCKS_PER_MSEC;  // время завершения 
	while (clock() < end_time) {}  // цикл ожидания времени 
}

int color(std::clock_t& start)
{
	int col;
	int g_time = 5;
	int y_time = 3;
	int r_time = 5;
	if (clock() - start > (2*g_time + 2*y_time + g_time) * CLOCKS_PER_SEC) start = clock() - g_time * CLOCKS_PER_SEC;
	if (clock() - start > (g_time + 2*y_time + g_time) * CLOCKS_PER_SEC) col = 0;
	else if(clock() - start > (g_time + y_time+ g_time) * CLOCKS_PER_SEC)col = 1;
	else if (clock() - start > (g_time+ y_time) * CLOCKS_PER_SEC)col = 2;
	else if (clock() - start > g_time * CLOCKS_PER_SEC)col = 1;
	else col = 0;
	return col;
}

template<class T>
void delPatrtisipant(vector<T>&Patrtisipant, TrafficLight& sbj )
{
	for (auto &i : Patrtisipant)
		if (i.getDistance() < 0)
		{
			//i.newCar();
			sbj.del(&i);
		}
}

