#include "Revista.h"

Revista::Revista(string titlu, int nrArticole)
{
	this->titlu = titlu;
	this->nrArticole = nrArticole;
}

string Revista::GetInfo() 
{
	string s;
	s += "Revista ";
	s += titlu;
	s += " cu ";
	s += nrArticole;
	s += " articole";
	return s;
}
