#ifndef ZAD1_NEW_FILE_OPERATIONS_H
#define ZAD1_NEW_FILE_OPERATIONS_H

extern int countCharsInFile(char *file, char chr);

extern void saveToFile(char *filePath, char *text);

extern FILE *openFile(char *filePath, char *flags);

#endif //ZAD1_NEW_FILE_OPERATIONS_H
