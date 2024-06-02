#pragma once
#include "Procesor.h"
class ComputeVowels :
    public Procesor
{
private:
    string Name;
public:
    ComputeVowels(string name);
    string GetName();
    int Compute(string s);
};

