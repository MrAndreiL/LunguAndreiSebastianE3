#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>
#include <string.h>
#include <errno.h>

static int isValidnumber;
int stringToint(char *str)
{
    // Converts a string into a number
    // ... e.g. '123' -> 123, '-45' -> '45'
    // '123a4b' -> error and set isValidnumber to 0
    isValidnumber = 1;
    int number, sign;
    if (str[0] == '-') {
	sign = -1;
	number = 0;
    }
    else {
	sign = 1;
	number = str[0] - '0';
    }
    for (int i = 1; str[i] != 0; i++) {
	if ('0' <= str[i] && str[i] <= '9')
	   number = number * 10 + (str[i] - '0');
	else {
	   isValidnumber = 0;
	   return -1;
	}
    }
    number *= sign;
    return number;
}

int main(int argc, char **argv)
{
    // Input check.
    if (argc != 2) {
	fprintf(stdout,"Format: %s <filename.txt>\n", argv[0]);
	return -1;
    }
    // Make sure the file is a regular file.
    int fd;
    if ((fd = open(argv[1], O_RDONLY)) == -1) {
	fprintf(stdout, "%s\n", strerror(errno));
	return -1;
    }
    struct stat st;
    if (fstat(fd, &st) == -1 || !S_ISREG(st.st_mode)) {
	fprintf(stdout, "Error, invalid file!");
	return -1;
    }
    close(fd);
    // Open the file and read each line.
    FILE *fptr;
    if ((fptr = fopen(argv[1], "r")) == NULL) {
	fprintf(stdout, "%s\n", strerror(errno));
	return -1;
    }
    // Convert each line and compute the result.
    char str[100];
    int result = 0;
    while (fscanf(fptr, "%s", str) != EOF) {
    	int number = stringToint(str);
	if (!isValidnumber) {
            printf("Error, the file <%s> contains non-numerical values\n", argv[1]);
	    return -1;
	}
	result += number;
    }
    printf("%d\n", result);
    fclose(fptr);
    return 0;

}
