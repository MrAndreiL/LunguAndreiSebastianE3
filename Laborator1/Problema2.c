#include <stdio.h>
#include <string.h>
#define BuffSize 150

struct words {
    char word[BuffSize];
    size_t length;
};

static int isValidChr(char ch)
{
    // Only spaces and letter allowed.
    if ('A' <= ch && ch <= 'Z') return 1;
    if ('a' <= ch && ch <= 'z') return 1;
    if (ch == ' ') return 1;
    return 0;
}

static size_t splitStr(char *str, struct words buff[])
{
    // Split the entire string into words.
    // On success, return the number of words used to fill the buffer.
    // Otherwise, return -1 (if an error occured or non-text values are found).
    size_t wordcnt = 0;
    size_t lettercnt = 0;
    for (size_t i = 0; str[i + 1] != 0; i++) {
	// Make sure there are no invalid characters.
	if (!isValidChr(str[i])) return -1;
	// if a space is found, end the new word.
	if (str[i] == ' ' && lettercnt) {
	    buff[wordcnt++].length = lettercnt;
	    lettercnt = 0;
	} else if (str[i] != ' ') {
	    // Append the new letter.
	    lettercnt++;
	    strncat(buff[wordcnt].word, &str[i], 1); 
	}
    }
    buff[wordcnt++].length = lettercnt;
    return wordcnt;
}

int main (void) 
{
    // Read input string.
    char inputBuff[BuffSize];
    if (fgets(inputBuff, BuffSize, stdin) == NULL) {
	fprintf(stdin, "Failed to read input string");
	return -1;
    }
    // Split the input string into words.
    struct words splitBuff[BuffSize];
    size_t wordcnt;
    if ((wordcnt = splitStr(inputBuff, splitBuff)) == -1) {
	perror("Error occured when spliting the string (invalid characters)");
	return -1;
    }
    // Simple sorting algorithm based on finding the maximum number each iteration.
    for (size_t i = 0; i < wordcnt; i++) {
	int pozMax = 0;
	for (int j = 1; j < wordcnt; j++)
	    if (splitBuff[j].length > splitBuff[pozMax].length)
		pozMax = j;
	printf("%s\n", splitBuff[pozMax].word);
	splitBuff[pozMax].length = 0;
    }
    return 0;
}






