#include "BMW.h"
#include "Weather.h"

BMW::BMW()
{
	if (Weather::Sunny)
		this->speed = 90;
	else
		if (Weather::Rain)
			this->speed = 60;
		else
			this->speed = 40;
	this->fuel_capacity = 60;
	this->fuel_consumption = 30;
}

int BMW::DidNotFinish(int lenght)
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
float BMW::RaceTime(int lenght)
{
	///t=v/d
	if (DidNotFinish(lenght) == true)
	{
		float time = float(this->speed) / float(lenght);
		return time;
	}
	return -1;
}
const char* BMW::GetName()
{
	return "BMW";
}