#pragma once
#include "Weather.h"
#include "Car.h"
class Circuit
{
private:
	///enum Weather;
	int lenght=0;
	Weather weather;
	Car** cars;
	int numCars = 0;
public:
	Circuit();
	void SetWeather(Weather x);
	void SetLength(int x);
	void Race();
	void AddCar(Car* c);
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

