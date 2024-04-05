#pragma once
#include "Car.h"
class Fiat :
    public Car
{
public:
    Fiat();
    const char* GetName();
    float RaceTime(int lenght);
    int DidNotFinish(int lenght);
};

