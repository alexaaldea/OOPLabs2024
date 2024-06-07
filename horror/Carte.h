#pragma once
#include<string>
using namespace std;
class Carte {
public:
	virtual ~Carte() = default;
	virtual string GetInfo() = 0;
};