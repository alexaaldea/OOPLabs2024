#include "Biblioteca.h"
#include <iostream>
using namespace std;
Biblioteca::Biblioteca()
{
	this->count = 0;
	carti = new Carte* [100];
}
Biblioteca::~Biblioteca()
{
	int i;
	for (i = 0; i < count; i++)
		delete carti[i];
	delete[] carti;
	this->count = 0;
}
Biblioteca& Biblioteca::operator+=(Carte* op)
{
	carti[count] = op;
	count++;
	return (*this);
}
Carte* Biblioteca::begin() const
{
	return carti[0];
}
Carte* Biblioteca::end() const
{
	return carti[count-1];
}
Biblioteca::operator int()
{
	return count;
}

void Biblioteca::PrintFilter(function<bool(Carte*)>Filter)
{
	int i;
	for (i = 0; i < count; i++)
		if (Filter(carti[i]))
			cout << carti[i]->GetInfo()<< '\n';
}
