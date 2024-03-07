#pragma once
class students
{
	char name[50];
	float GradeMath;
	float GradeEnglish;
	float GradeHistory;
public:
	void SetName(char InputName[50]);
	char* GetName();

	void SetGradeMath(float InputGradeMath);
	float GetGradeMath();

	void SetGradeEnglish(float InputGradeEnglish);
	float GetGradeEnglish();

	void SetGradeHistory(float InputGradeHistory);
	float GetGradeHistory();

	float AverageGrade();
};

