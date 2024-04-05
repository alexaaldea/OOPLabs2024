#include "Circuit.h"
#include <stdio.h>

Circuit::Circuit()
{
	cars = new Car*[20];
	numCars = 0;
	lenght = 0;
	weather=Weather::Sunny;
}
void Circuit::SetLength(int x)
{
	this->lenght = x;
}
void Circuit::SetWeather(Weather x)
{
	this->weather = x;
}
void Circuit::AddCar(Car* c)
{
	cars[numCars] = c;
	numCars++;
}
void Circuit::Race()
{
	int i;
	float time;
	printf("Lungimea circuitului este: %d\n", lenght);

	for (i = 0; i < numCars; i++)
	{
		time = cars[i]->RaceTime(lenght);
		if (time == -1)
			printf("The car that did not finish the race is: %s\n", cars[i]->GetName());
		else
		{
			printf("The car with the name %s finished the race in %f\n", cars[i]->GetName(), time);
		}

	}
}
void Circuit::ShowFinalRanks()
{
	int i, j;
	Car ** carsAux = new Car* [20];
	Car ** aux=new Car*[1];
	for (i = 0; i < numCars; i++)
		carsAux[i] = cars[i];
	for(i=0; i<numCars-1; i++)
		for(j=i+1; j<numCars; j++)
			if (carsAux[i]->RaceTime(lenght) < carsAux[j]->RaceTime(lenght))
			{
				aux[1] = carsAux[i];
				carsAux[i] = carsAux[j];
				carsAux[j] = aux[1];
			}
	int nr = 1;
	printf("Clasamentul masinilor este: \n");
	for (i = 0; i < numCars; i++)
		if (carsAux[i]->RaceTime(lenght) > 0)
		{
			printf("Pe locul %d se afla masina %s \n", nr, carsAux[i]->GetName());
			nr++;
		}
}
void Circuit::ShowWhoDidNotFinish()
{
	int i;
	printf("Masinile care nu au terminat cursa sunt:\n");
	for (i = 0; i < numCars; i++)
		if (cars[i]->RaceTime(lenght) < 0)
			printf("%s\n", cars[i]->GetName());
}
