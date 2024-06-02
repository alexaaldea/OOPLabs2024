#pragma once
#include "Procesor.h"
#include <string>
#include <vector>
using namespace std;
class Sentence
{
private:
	string Name;
	vector<Procesor *> tasks;
public:
	Sentence(string s);
	void RunAll();
	void ListAll();
	void Run(string s);
	Sentence& operator +=(Procesor* p);
};

