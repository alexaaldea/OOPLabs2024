#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include <cstring>

void Movie::set_name(char InputName[256])
{
	strcpy(this->name, InputName);
}
char* Movie::GetName()
{
	return this->name;
}

void Movie::set_year(int InputReleaseDate)
{
	this->ReleaseDate = InputReleaseDate;
}
int Movie::GetReleaseDate()
{
	return this->ReleaseDate;
}

void Movie::set_score(double InputScore)
{
	this->Score = InputScore;
}
double Movie::GetScore()
{
	return this->Score;
}

void Movie::set_length(int InputLenght)
{
	this->Lenght = InputLenght;
}
int Movie::GetLenghtMovie()
{
	return this->Lenght;
}

int Movie::PassedYears()
{
	return (2024 - GetReleaseDate());
}