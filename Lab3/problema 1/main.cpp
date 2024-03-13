#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include<iostream>


int main()
{
	Math fct;
	int a = 23, b = 34, c = 124;
	double ad = 0.5, bd = 10.0, cd = 3.0;
	char s1[] = "18", s2[] = "12";

	printf("%d\n", fct.Add(a, b));
	printf("%d\n", fct.Add(a, b, c));
	printf("%d\n", fct.Add(ad, bd));
	printf("%d\n", fct.Add(ad, bd, cd));
	printf("%d\n", fct.Mul(a, b));
	printf("%d\n", fct.Mul(a, b, c));
	printf("%d\n", fct.Mul(ad, bd));
	printf("%d\n", fct.Mul(ad, bd, cd));
	printf("%d\n", fct.Add(6, a, b, c, 23, 35, 212));
	printf("%s\n", fct.Add(s1, s2));
	return 0;
}