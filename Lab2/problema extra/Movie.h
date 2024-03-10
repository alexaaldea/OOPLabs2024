#pragma once
class Movie
{
	double Score;
	int ReleaseDate;
	int Lenght;
	char name[256];
public:
	void set_name(char InputName[256]);
	char* GetName();

	void set_year(int InputReleaseDate);
	int GetReleaseDate();

	void set_score(double InputScore);
	double GetScore();

	void set_length(int InputLenght);
	int GetLenghtMovie();

	int PassedYears();
};

