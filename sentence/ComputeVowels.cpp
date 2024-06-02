#include "ComputeVowels.h"

ComputeVowels::ComputeVowels(string name)
{
	Name = name;
}
string ComputeVowels::GetName()
{
	return this->Name;
}
int ComputeVowels::Compute(string s)
{
	int i, nr = 0;
	for (i = 0; i < s.size(); i++)
		if (strchr("aeiouAEIOU", s[i]) != 0)
			nr++;
	return nr;
}
