#include <stdio.h>
#include <stdlib.h>
#include "file_operations/file_operations.h"
#include "functions/functions.h"


char *formatResponse(char const *format, char *letter, char *inputFileName, int counter) {
    size_t needed = snprintf(NULL, 0, format, letter, inputFileName, counter) + 1;
    char *buffer = malloc(needed);
    sprintf(buffer, format, letter, inputFileName, counter);
    return buffer;
}

int main(int argc, char *argv[]) {

    char *inputFileName = getParameterByName("i", argv, argc);
    char *letter = getParameterByName("l", argv, argc);

    int counter = countCharsInFile(inputFileName, letter[0]);

    char *message = formatResponse("Counter of '%s' letter in file '%s' is: %d", letter, inputFileName, counter);

    saveToFile(getParameterByName("o", argv, argc), message);

    return 0;
}