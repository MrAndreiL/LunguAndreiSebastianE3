#include "student.h"
#include "functions.h"
#include <iostream>

int main()
{
	// Set the students' names.
	Student st1, st2;
	if (!st1.setName("Marius")) {
		perror("Invalid name");
		return -1;
	}
	if(!st2.setName("Maria")) {
		perror("Invalid name");
		return -1;
	}
	printf("Name: %s\n", st1.getName());
	printf("Name: %s\n", st2.getName());
	// Set the math grades.
	if(!st1.setMathGrade(7.4)) {
		perror("Invalid grade");
		return -1;
	}
	if(!st2.setMathGrade(9.0)) {
		perror("Invalid grade");
		return -1;
	}
	printf("Math: %s %.2f\n", st1.getName(), st1.getMathGrade());
	printf("Math: %s %.2f\n", st2.getName(), st2.getMathGrade());
	// Set the English grades.
	if (!st1.setEngGrade(9.0)) {
		perror("Invalid Grade");
		return -1;
	}
	if (!st2.setEngGrade(10.0)) {
		perror("Invalid Grade");
		return -1;
	}
	printf("English: %s %.2f\n", st1.getName(), st1.getEngGrade());
	printf("English: %s %.2f\n", st2.getName(), st2.getEngGrade());
	// Set the History grades.
	if (!st1.setHistoryGrade(6.70)) {
		perror("Invalid Grade");
		return -1;
	}
	if (!st2.setHistoryGrade(9.95)) {
		perror("Invalid Grade");
		return -1;
	}
	printf("History: %s %.2f\n", st1.getName(), st1.getHistoryGrade());
	printf("History: %s %.2f\n", st2.getName(), st2.getHistoryGrade());
	// Find the grade average.
	printf("Average Grade: %s %.2f\n", st1.getName(), st1.averageGrade());
	printf("Average Grade: %s %.2f\n", st2.getName(), st2.averageGrade());
	// Compare length.
	printf("Compare name: %d\n", compareName(st1.getName(), st2.getName()));
	// Compare grades.
	printf("Compare Math grade: %d\n", compareGrade(st1.getMathGrade(), st2.getMathGrade()));	
	printf("Compare English grade: %d\n", compareGrade(st1.getEngGrade(), st2.getEngGrade()));
	printf("Compare History grade: %d\n", compareGrade(st1.getHistoryGrade(), st2.getHistoryGrade()));
	printf("Compare average grade: %d\n", compareGrade(st1.averageGrade(), st2.averageGrade()));
	return 0;
}
