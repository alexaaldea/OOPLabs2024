#include "Volvo.h"
#include "Weather.h"

Volvo::Volvo()
{
	if (Weather::Sunny)
		this->speed = 95;
	else
		if (Weather::Rain)
			this->speed = 65;
		else
			this->speed = 55;
	this->fuel_capacity = 65;
	this->fuel_consumption = 70;
}
const char* Volvo::GetName()
{
	return "Volvo";
}
int Volvo::DidNotFinish(int lenght)
{
	float parcurs = 0;
	float usedFuel = 0;
	while (lenght > parcurs && lenght - parcurs >= 100)
	{
		parcurs += 100;
		usedFuel += fuel_consumption;
	}
	if (lenght - parcurs < 100 && lenght - parcurs>0)
	{
		usedFuel += (fuel_capacity * (lenght - parcurs)) / 100;
	}
	if (usedFuel <= fuel_capacity)
		return true;
	return false;
}
float Volvo::RaceTime(int lenght)
{
	///t=v/d
	if (DidNotFinish(lenght) == true)
	{
		float time = float(this->speed )/ float(lenght);
		return time;
	}
	return -1;
}
