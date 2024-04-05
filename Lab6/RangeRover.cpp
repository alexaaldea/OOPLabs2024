#include "RangeRover.h"
#include "Weather.h"

RangeRover::RangeRover()
{
	if (Weather::Sunny)
		this->speed = 97;
	else
		if (Weather::Rain)
			this->speed = 70;
		else
			this->speed = 50;
	this->fuel_capacity=70;
	this->fuel_consumption=20;
}


int RangeRover::DidNotFinish(int lenght)
{
	float parcurs=0;
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
const char* RangeRover::GetName()
{
	return "RangeRover";
}
float RangeRover::RaceTime(int lenght)
{
	///t=v/d
	if (DidNotFinish(lenght) == true)
	{
		float time = float(this->speed) / float(lenght);
		return time;
	}
	return -1;
}