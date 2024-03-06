#include "NumberList.h"
#include <stdio.h>
void NumberList::Init()
{
	count = 0;
}

bool NumberList::Add(int x)
{
	if (count >= 10)
		return false;
	numbers[count] = x;
	count++;
}

void NumberList::Sort()
{
	int i, j, aux;
	for(i=0; i<count-1; i++)
		for(j=i+1; j<count; j++)
			if (numbers[i] > numbers[j])
			{
				aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
}

void NumberList::Print()
{
	int i;
	for (i = 0; i < count; i++)
		printf("%d\n", numbers[i]);
}
