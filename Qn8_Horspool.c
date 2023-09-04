#include <stdio.h>
#include <string.h>

#define MAX_ALPHABET_SIZE 256

int shiftTable[MAX_ALPHABET_SIZE];

void createShiftTable(char pattern[]) {
    int i, j, patternLength;
    patternLength = strlen(pattern);

    for (i = 0; i < MAX_ALPHABET_SIZE; i++)
        shiftTable[i] = patternLength;

    for (j = 0; j < patternLength - 1; j++)
        shiftTable[pattern[j]] = patternLength - 1 - j;
}

int horspoolSearch(char text[], char pattern[]) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int i = patternLength - 1;

    while (i < textLength) {
        int k = 0;
        while (k < patternLength && pattern[patternLength - 1 - k] == text[i - k])
            k++;

        if (k == patternLength)
            return i - patternLength + 1;
        else
            i += shiftTable[text[i]];
    }
    return -1;
}

int main() {
    char text[500], pattern[100];
    int position;

    printf("Enter the text in which the pattern is to be searched:\n");
    gets(text); // You might consider using fgets for safer input.
    printf("Enter the pattern to be searched:\n");
    gets(pattern);

    createShiftTable(pattern);
    position = horspoolSearch(text, pattern);

    if (position >= 0)
        printf("The desired pattern was found starting from position %d\n", position + 1);
    else
        printf("The pattern was not found in the given text\n");

    return 0;
}
