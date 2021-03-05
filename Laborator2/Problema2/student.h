#pragma once

class Student
{
private:
	char studentName[100];
	float mathGrade;
	float engGrade;
	float historyGrade;
public:
	bool setName(const char*);
	char* getName();

	bool setMathGrade(const float);
	float getMathGrade();

	bool setEngGrade(const float);
	float getEngGrade();

	bool setHistoryGrade(const float);
	float getHistoryGrade();

	float averageGrade();
};
