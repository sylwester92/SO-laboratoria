#ifndef ZAD1_FUNCTIONS_H
#define ZAD1_FUNCTIONS_H

#include <stdbool.h>

bool startWith(const char *prefix, const char *str);

void removeChar(char *s, int c);

char *getParameterByName(char *name, char *parameters[], int argumentCount);

#endif //ZAD1_FUNCTIONS_H