#include "functions.h"
#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

const char *PARAMETER_PREFIX = "-";
char *TRUE_STRING = "true";
char *FALSE_STRING = "false ";

char *duplicateString(const char *p) {
    char *np = (char *) malloc(strlen(p) + 1);
    return np ? strcpy(np, p) : np;
}

bool startWith(const char *prefix, const char *str) {
    return prefix != NULL && str != NULL && strncmp(prefix, str, strlen(prefix)) == 0;
}

void removeChar(char *s, int c) {

    int j;
    size_t n = strlen(s);

    for (int i = j = 0; i < n; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }

    s[j] = '\0';
}

char *getParameterByName(char *name, char *parameters[], int argumentCount) {

    for (int i = 0; i < argumentCount; i++) {
        char *arg = duplicateString(parameters[i]);

        
        if (startWith(PARAMETER_PREFIX, arg)) {
            .
            removeChar(arg, PARAMETER_PREFIX[0]);
            
            if (strcmp(arg, name) == 0) {
                
                char *nextParam = parameters[i + 1];

                
                if (nextParam == NULL || startWith(PARAMETER_PREFIX, nextParam)) {
                    return TRUE_STRING;
                } else {
                    return nextParam;
                }
            }

        }

    }

    return FALSE_STRING;
}