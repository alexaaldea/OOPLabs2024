#pragma once
#include "Car.h"
class Volvo :
    public Car
{
public:
    Volvo();
    const char* GetName();
    float RaceTime(int lenght);
    int DidNotFinish(int lenght);
};

