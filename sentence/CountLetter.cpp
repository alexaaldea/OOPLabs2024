#include "CountLetter.h"

CountLetter::CountLetter(string name, function<bool(char)> predicate)
{
	this->Name = name;
	this->predicate = predicate;
}
string CountLetter::GetName()
{
	return this->Name;
}
int CountLetter::Compute(string s)
{
	int i, nr=0;
	for (i = 0; i < s.size(); i++)
		if (predicate(s[i]))
			nr++;
	return nr;
}
