#pragma once
#include "Car.h"
class BMW :
    public Car
{
public:
    BMW();
    float RaceTime(int lenght);
    const char* GetName();
    int DidNotFinish(int lenght);
};

