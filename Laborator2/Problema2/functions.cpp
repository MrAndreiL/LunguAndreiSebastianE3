#include "functions.h"

static int stringLength(const char* str) 
{
	// Return the string length.
	if (!str) return 0;
	int i;
	for (i = 0; str[i] != 0; i++)
		;
	return i;
}

int compareName(const char* name1, const char* name2)
{
        // Compare two names.
        // Return -1 if name1 is smaller lexicographically than name2.
        // Return 1 if name2 is smaller.
        // Return 0 if the names are equal.
        int n1 = stringLength(name1);
        int n2 = stringLength(name2);
        int i  = 0;
        while (name1[i] == name2[i]) {
                if (name1[i] == '\0') return 0;
                i++;
        }
        if (name1[i] < name2[i]) return -1;
        return 1;
}

int compareGrade(const float grade1, const float grade2)
{
	if (grade1 == grade2) return 0;
	return grade1 > grade2 ? 1 : -1;
}
