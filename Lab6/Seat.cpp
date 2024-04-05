#include "Seat.h"
#include "Weather.h"

Seat::Seat()
{
	if (Weather::Sunny)
		this->speed = 150;
	else
		if (Weather::Rain)
			this->speed = 120;
		else
			this->speed = 100;
	this->fuel_capacity = 90;
	this->fuel_consumption = 30;
}
const char* Seat::GetName()
{
	return "Seat";
}
int Seat::DidNotFinish(int lenght)
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
float Seat::RaceTime(int lenght)
{
	///t=v/d
	if (DidNotFinish(lenght) == true)
	{
		float time = float(this->speed)/ float(lenght);
		return time;
	}
	return -1;
}