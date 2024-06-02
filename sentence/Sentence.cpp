#include "Sentence.h"
#include <iostream>

Sentence::Sentence(string s)
{
	this->Name = s;
}
void Sentence::RunAll()
{
	for (auto i : tasks)
	{
		cout << "Name: " << i->GetName() << " => " << i->Compute(Name)<<'\n';
	}
}
void Sentence::ListAll()
{
	for (auto i : tasks)
	{
		cout << "Name: " << i->GetName() << '\n';
	}
}
void Sentence::Run(string s)
{
	for (auto i : tasks)
		if (i->GetName() == s)
			cout<<i->Compute(Name)<<'\n';
}
Sentence& Sentence::operator +=(Procesor* p)
{
	tasks.push_back(p);
	return (*this);
}
