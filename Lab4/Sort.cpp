#include "Sort.h"
#include <iostream>
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cstring>
using namespace std;
Sort::Sort(int numar_elemente, int min_element, int max_element)
{
	v = new int[numar_elemente];
	this->count = numar_elemente;
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < numar_elemente; i++)
		this->v[i] = min_element + rand() % (max_element - min_element + 1);
}
Sort::Sort(int* vector, int numar_elemente)
{
	v = new int[numar_elemente];
	this->count = numar_elemente;
	for (int i = 0; i < count; i++)
		v[i] = 0;
	for (int i = 0; i < count; i++)
	   	 v[i] = vector[i];
}
Sort::Sort(int count, ...)
{
	this->v = new int[count];
	this->count = count;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++)
	{
		this->v[i] = va_arg(vl, int);
	}
	va_end(vl);
}

Sort::Sort(const char* c)
{
	int aux = 0, i, lg=0;
	for (i = 0; c[i] != '\0'; i++)
		if (c[i] == ',')
			lg++;
	lg++;
	this -> count = 0;
	v = new int[lg];
	for (i = 0; c[i]!='\0'; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
			aux = aux * 10 + (c[i] - '0');
		   else
				if (c[i] == ',')
				{
					this->v[count] = aux;
					count++;
					aux = 0;
				}
	}
	this->v[count] = aux;
	count++;
	aux = 0;
}
Sort::Sort(int nrelem, bool a) : v(new int[nrelem] {1, 2, 7, 4, 5, 6, 3})
{
	this->count = nrelem;
}

void Sort::InsertSort(bool ascendent)
{
	int i, key, j;
	for (i = 1; i < count; i++) {
			key = v[i];
			j = i - 1;
			while (j >= 0 && v[j] > key) {
				v[j + 1] = v[j];
				j = j - 1;
			}
			v[j + 1] = key;
		}
}
void Sort::QuickSort(bool ascendent)
{
	quickSort(ascendent, 0, count - 1);
}
void Sort::quickSort(bool ascendent, int start, int end)
{
	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(v, start, end);

	// Sorting the left part
	quickSort(v, start, p - 1);

	// Sorting the right part
	quickSort(v, p + 1, end);
}
int Sort::partition(int* v, int start, int end)
{

	int pivot = v[start];

	int lg = 0;
	for (int i = start + 1; i <= end; i++) {
		if (v[i] <= pivot)
			lg++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + lg;
	swap(v[pivotIndex], v[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (v[i] <= pivot) {
			i++;
		}

		while (v[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(v[i++], v[j--]);
		}
	}

	return pivotIndex;
}

void Sort::BubbleSort(bool ascendent)
{
	int i, j;
	bool swapped;
	for (i = 0; i < count - 1; i++) {
		swapped = false;
		for (j = 0; j < count - i - 1; j++) {
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
				swapped = true;
			}
		}

		// If no two elements were swapped
		// by inner loop, then break
		if (swapped == false)
			break;
	}
}
void Sort::Print()
{
	int i;
	for (i = 0; i < count; i++)
		printf("%d ", v[i]);
	printf("\n");
}
int  Sort::GetElementsCount()
{
	return this->count;
}
int  Sort::GetElementFromIndex(int index)
{
	if (index > 0 && index < count)
		return this->v[index];
	printf("Elementul nu exista in vector \n");
	return -1;

}