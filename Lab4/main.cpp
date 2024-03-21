#include "Sort.h"
#include <stdlib.h>
#include <iostream>

int main()
{
	Sort c1(10, 9, 100);///random bun
	c1.BubbleSort();
	c1.Print();

	Sort c5(7, true);
	c5.BubbleSort();
	c5.Print();

	Sort c3(6, 1, 2, 3, 4, 5, 6);///lista bun
	c3.BubbleSort();
	c3.Print();

	int v[6] = { 1, 2, 3, 7, 5, 6};///vector facut bun
	Sort c2(v, 6);
	c2.BubbleSort();
	c2.Print();

	/*Sort sort4(5, 12, 34, 2, 35, 399);///lista bun
	sort4.InsertSort();
	sort4.Print();*/

	char sort5C[] = "34,223,45,2,67,64,28,123,123,0,323,9830";///sir de caractere bun
	Sort sort5(sort5C);
	sort5.QuickSort(true);
	sort5.Print();
	return 0;
}
