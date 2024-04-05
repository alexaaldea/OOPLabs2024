#pragma once
class Car
{
public:
	int speed;
	int fuel_capacity;
	int fuel_consumption;

	virtual float RaceTime(int lenght)=0;
	virtual const char* GetName()=0;
	virtual int DidNotFinish(int lenght)=0;
};

