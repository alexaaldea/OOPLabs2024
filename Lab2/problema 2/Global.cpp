#include "Global.h"
#include <cstring>
int CompareName(students* s1, students* s2)
{
	/*char nume1[50], nume2[50];
	s1->GetName(nume1);
	s2->GetName(nume2);
	return strcmp(nume1, nume2);*/
	return strcmp(s1->GetName(), s2->GetName());
}
int CompareGradeMath(students* s1, students* s2)
{
	if (s1->GetGradeMath() < s2->GetGradeMath())
		return -1;
	if (s1->GetGradeMath() > s2->GetGradeMath())
		return 1;
	return 0;
}
int CompareGradeEnglish(students* s1, students* s2)
{
	if (s1->GetGradeEnglish() < s2->GetGradeEnglish())
		return -1;
	if (s1->GetGradeEnglish() > s2->GetGradeEnglish())
		return 1;
	return 0;
}
int CompareGradeHistory(students* s1, students* s2)
{
	if (s1->GetGradeHistory() < s2->GetGradeHistory())
		return -1;
	if (s1->GetGradeHistory() > s2->GetGradeHistory())
		return 1;
	return 0;
}
int CompareGradeAverage(students* s1, students* s2)
{
	if (s1->AverageGrade() < s2->AverageGrade())
		return -1;
	if (s1->AverageGrade() > s2->AverageGrade())
		return 1;
	return 0;
}

