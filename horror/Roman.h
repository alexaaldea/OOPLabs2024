#pragma once
#include <iostream>
#include <string>
#include "Carte.h"

using namespace std;

class Roman :
    public Carte
{
    string nume;
    string autor;
public:
    Roman(string nume, string autor);
    string GetInfo();
};