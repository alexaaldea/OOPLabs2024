#include "Fiat.h"
#include "Weather.h"

Fiat::Fiat()
{
	if (Weather::Sunny)
		this->speed = 180;
	else
		if (Weather::Rain)
			this->speed = 125;
		else
			this->speed = 100;
	this->fuel_capacity = 85;
	this->fuel_consumption = 25;
}
const char* Fiat::GetName()
{
	return "Fiat";
}
int Fiat::DidNotFinish(int lenght)
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
float Fiat::RaceTime(int lenght)
{
	///t=v/d
	if (DidNotFinish(lenght) == true)
	{
		float time =float(this->speed) / float(lenght);
		return time;
	}
	return -1;
}
