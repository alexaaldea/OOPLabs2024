#pragma once
#include "Procesor.h"
class LongestWord :
    public Procesor
{
private:
    string Name;
public:
    LongestWord(string name);
    string GetName();
    int Compute(string s);
};

