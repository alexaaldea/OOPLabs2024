#pragma once
#include <functional>
#include "Carte.h"
using namespace std;

class Biblioteca
{
private:
	int count;
	Carte** carti;
public:
	Biblioteca();
	~Biblioteca();
	Biblioteca& operator+=(Carte* op);
	Carte* begin() const;
	Carte* end() const;
	operator int();
	void PrintFilter(function<bool(Carte*)>Filter);
};

