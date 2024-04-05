#pragma once
#include "Car.h"
class RangeRover :
    public Car
{
public:
    RangeRover();
    float RaceTime(int lenght);
    const char* GetName();
    int DidNotFinish(int lenght);
};
