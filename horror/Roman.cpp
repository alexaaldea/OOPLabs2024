#include "Roman.h"
using namespace std;

Roman::Roman(string nume, string autor)
{
	this->nume = nume;
	this->autor = autor;
}

string Roman::GetInfo()
{
	string s;
	s += "Roman ";
	s += nume;
	s += " de ";
	s += autor;
	return s;
}


