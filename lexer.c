#include "lexer.h"
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>

Token *tokenize(const char *src, int *out_count) {
    int i = 0;

    while (src[i] != '\0') {
        char c = src[i];
        printf("Char [%d]: '%c'\n", i, c);
        i++;
    }

    *out_count = 0;
    return NULL;
}