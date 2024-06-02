#pragma once
#include "Procesor.h"
#include <functional>
#include <iostream>
using namespace std;

class CountLetter :
    public Procesor
{
private:
    string Name;
    function<bool(char)> predicate;
public:
    CountLetter(string name, function<bool(char)> predicate);
    string GetName();
    int Compute(string s);
};

