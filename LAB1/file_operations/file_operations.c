#include <stdio.h>
#include <stdlib.h>
#include "file_operations.h"

FILE *openFile(char *filePath, char *flags) {

    FILE *file = fopen(filePath, flags);

    if (file == NULL) {
        fprintf(stderr, "Cannot open file: %s", filePath);
        exit(EXIT_FAILURE);
    }

    return file;
}

int countCharsInFile(char *filePath, char chr) {

    int counter = 0;

    FILE *file = openFile(filePath, "r");

    for (char ch = (char) fgetc(file); ch != EOF; ch = (char) fgetc(file)) {
        if (ch == chr) {
            counter++;
        }
    }

    fclose(file);

    return counter;
}

void saveToFile(char *filePath, char *text) {
    FILE *file = openFile(filePath, "wb");
    fputs(text, file);
    fclose(file);
}