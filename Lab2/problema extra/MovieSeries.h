#pragma once
#include "Movie.h"
class MovieSeries
{
private:
	Movie* movies[16];
	int count;
public:
	void init();
	bool add(Movie* movie);
	void print();
	void sort();
};

