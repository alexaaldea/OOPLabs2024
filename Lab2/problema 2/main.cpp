#define _CRT_SECURE_NO_WARNINGS
#include "students.h"
#include "Global.h"
#include <cstring>
#include <stdio.h>
using namespace std;

int main()
{
	students student1;
	char nume1[50],nume2[50];
	strcpy(nume1, "CRISTI");
	student1.SetName(nume1);
	printf("Numele este: %s\n", student1.GetName());

	student1.SetGradeMath(5.0f);
	printf("Nota la mate este: %f\n", student1.GetGradeMath());

	student1.SetGradeEnglish(4.0f);
	printf("Nota la engleza este: %f\n", student1.GetGradeEnglish());

	student1.SetGradeHistory(6.0f);
	printf("Nota la istorie este: %f\n", student1.GetGradeHistory());

	printf("Media materiilor este: % f\n", student1.AverageGrade());

	students student2;
	char nume3[50], nume4[50];
	strcpy(nume3, "ALEX");
	student2.SetName(nume3);
	student2.GetName();

	student2.SetGradeMath(10.0f);
	student2.SetGradeEnglish(3.0f);
	student2.SetGradeHistory(6.0f);
	printf("Media materiilor este: % f\n", student2.AverageGrade());
	printf("Studentul cu numele mai mare este %d\n", CompareName(&student1, &student2));
	printf("Studentul cu nota mai mare este %d\n", CompareGradeMath(&student1, &student2));
	printf("Studentul cu nota mai mare este %d\n", CompareGradeEnglish(&student1, &student2));
	printf("Studentul cu nota mai mare este %d\n", CompareGradeHistory(&student1, &student2));
	printf("Studentul cu nota mai mare este %d\n", CompareGradeAverage(&student1, &student2));
}
