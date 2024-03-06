#include "NumberList.h"
#include <stdio.h>
using namespace std;

int main()
{
	int i;
	NumberList myClass;

	myClass.Init();

	for (i = 20; i >= 11; i--)
		myClass.Add(i);
	myClass.Add(30);///nu se va adauga

	myClass.Sort();
	myClass.Print();
}
