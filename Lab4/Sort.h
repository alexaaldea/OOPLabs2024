#pragma once

class Sort
{
    int* v;
    int count;
public:
    Sort(int numar_elemente, int min_element, int max_element);
    Sort(int* vector, int numar_elemente);
    Sort(int count, ...);
    Sort(const char* c);
    Sort(int nrelem, bool a);
    // add constuctors
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    int partition(int* v, int start, int end);
    void quickSort(bool ascendent, int start, int end);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
