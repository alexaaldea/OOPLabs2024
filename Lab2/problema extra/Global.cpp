#include "Global.h"
#include <cstring>
int movie_compare_name(Movie* m1, Movie* m2)
{
	return strcmp(m1->GetName(), m2->GetName());
}
int movie_compare_year(Movie* m1, Movie* m2)
{
	if (m1->GetReleaseDate() < m2->GetReleaseDate())
		return -1;
	if (m1->GetReleaseDate() > m2->GetReleaseDate())
		return 1;
	return 0;
}
int movie_compare_score(Movie* m1, Movie* m2)
{
	if (m1->GetScore() < m2->GetScore())
		return -1;
	if (m1->GetScore() > m2->GetScore())
		return 1;
	return 0;
}
int movie_compare_lenght(Movie* m1, Movie* m2)
{
	if (m1->GetLenghtMovie() < m2->GetLenghtMovie())
		return -1;
	if (m1->GetLenghtMovie() > m2->GetLenghtMovie())
		return 1;
	return 0;
}
int movie_compare_passed_years(Movie* m1, Movie* m2)
{
	if (m1->PassedYears() < m2->PassedYears())
		return -1;
	if (m1->PassedYears() > m2->PassedYears())
		return 1;
	return 0;
}