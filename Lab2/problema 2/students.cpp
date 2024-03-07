#define _CRT_SECURE_NO_WARNINGS
#include "students.h"
#include <cstring>

void students::SetName(char InputName[50])
{
	strcpy(this->name, InputName);
}

char* students::GetName()
{
	return this->name;
}

void students::SetGradeMath(float InputGradeMath)
{
	if(InputGradeMath>=0 && InputGradeMath<=10)
	  this->GradeMath = InputGradeMath;
}

float students::GetGradeMath()
{
	return this->GradeMath;
}

void students::SetGradeEnglish(float InputGradeEnglish)
{
	if (InputGradeEnglish >= 0 && InputGradeEnglish <= 10)
	    this->GradeEnglish = InputGradeEnglish;
}

float students::GetGradeEnglish()
{
	return this->GradeEnglish;
}

void students::SetGradeHistory(float InputGradeHistory)
{
	if (InputGradeHistory >= 0 && InputGradeHistory <= 10)
	    this->GradeHistory = InputGradeHistory;
}

float students::GetGradeHistory()
{
	return this->GradeHistory;
}

float students::AverageGrade()
{
	float avg;
	avg = float((float(this->GetGradeHistory()) + float(this->GetGradeEnglish()) + float(this->GetGradeMath())) / 3);
	return float(avg);
}

