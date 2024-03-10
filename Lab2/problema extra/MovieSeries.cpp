#include "MovieSeries.h"

#include <stdio.h>
void MovieSeries::init()
{
	count = 0;
}
bool MovieSeries::add(Movie* movie)
{
    if (count >= 16)
        return false;
    movies[count] = movie;
    count++;
    return true;
}
void MovieSeries::print()
{
    int i;
    for (i = 0; i < count; i++)
    {
        printf("Numele este: %s\n", movies[i]->GetName());
        printf("Durata filmului este: %d\n", movies[i]->GetLenghtMovie());
        printf("Anul lansarii este: %d\n", movies[i]->GetReleaseDate());
        printf("Scorul este: %f\n", movies[i]->GetScore());
        printf("Ani de la aparitie: %d\n", movies[i]->PassedYears());
    }
}
void MovieSeries::sort()
{
    int i, j, aux1;
    int years[16];
    Movie* aux2;
    for (i = 0; i < count; i++)
    {
        years[i] = movies[i]->PassedYears();
    }
    for(i=0; i<count-1; i++)
        for(j=i+1; j<count; j++)
            if (years[i] < years[j])
            {
                aux1 = years[i];
                years[i] = years[j];
                years[j] = aux1;

                aux2 = movies[i];
                movies[i] = movies[j];
                movies[j] = aux2;
            }
    for (i = 0; i < count; i++)
        printf("Numele: %s\n", movies[i]->GetName());
}
