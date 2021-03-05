#include "student.h"
#include <string.h>

bool Student::setName(const char* Name)
{
	// Update the student's name
	// Return true if the name has been update successfully
	// false if an error occured.
	if (!Name) return false;
	size_t dstSize = strlen(Name) + 1;
	strncpy(studentName, Name, dstSize);
	return true;
}

char* Student::getName()
{
	return studentName;
}

bool Student::setMathGrade(const float grade)
{
	// Update the student's math grade
	// return true if the grade has been updated successfully 
	// false if an error occured
	if (grade < 1.0 || grade > 10.0) return false;
	mathGrade = grade;
	return true;
}

float Student::getMathGrade()
{
	return mathGrade;
}

bool Student::setEngGrade(const float grade)
{
	// Update the student's English grade.	
	// return true if the grade has been updated successfully
	// false otherwise
	if (grade < 1.0 || grade > 10.0) return false;
	engGrade = grade;
	return true;
}

float Student::getEngGrade()
{
	return engGrade;
}

bool Student::setHistoryGrade(const float grade)
{
	// Update the student's History grade.
	// return true if the grade has been updated successfully
	// false otherwise
	if (grade < 1.0 || grade > 10.0) return false;
	historyGrade = grade;
	return true;
}

float Student::getHistoryGrade()
{
	return historyGrade;
}

float Student::averageGrade() 
{
	return (mathGrade + engGrade + historyGrade) / 3;
}
