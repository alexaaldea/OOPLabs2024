#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include "Global.h"
#include "MovieSeries.h"
#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
	Movie m1;
	char nume1[256];
	strcpy(nume1, "Avengers: End Game");
	m1.set_name(nume1);
	printf("Numele este: %s\n", m1.GetName());

	m1.set_length(240);
	printf("Durata filmului este: %d\n", m1.GetLenghtMovie());

	m1.set_year(2019);
	printf("Anul lansarii este: %d\n", m1.GetReleaseDate());

	m1.set_score(9.60f);
	printf("Scorul este: %f\n", m1.GetScore());

	printf("Ani de la aparitie: %d\n", m1.PassedYears());

	Movie m2;
	char nume2[256];
	strcpy(nume2, "Cenusareasa");
	m2.set_name(nume2);

	m2.set_length(240);
	m2.set_year(2020);
	m2.set_score(8.40f);
	printf("Filmul cu numele mai mare este %d\n", movie_compare_name(&m1, &m2));
	printf("Filmul cu data mai mare este %d\n", movie_compare_year(&m1, &m2));
	printf("Filmul cu scorul mai mare este %d\n", movie_compare_score(&m1, &m2));
	printf("Filmul cu durata mai mare este %d\n", movie_compare_lenght(&m1, &m2));
	printf("Filmul cu anii mai mari este %d\n", movie_compare_passed_years(&m1, &m2));
	printf("\n");

	MovieSeries series;
	series.init();
	series.add(&m1);
	series.add(&m2);

	series.sort();
	printf("\n");
	series.print();

}