#include "lexer.h"
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

Token *tokenize(const char *src, int *out_count) {
    int i = 0;
    Token *tokens = NULL;
    int count = 0;

    while (src[i] != '\0') {
        char c = src[i];
        if (isdigit(c)) {
            int start = i;
            while (isdigit(c)) {
                i++;
                c = src[i];
            }
            int end = i;
            int len = end - start;
            char *word = malloc(len + 1);
            memcpy(word, &src[start], len);
            word[len] = '\0';
            tokens = realloc(tokens, sizeof(Token) * (count + 1));
            tokens[count].type = INT;
            tokens[count].text = word;
            tokens[count].line = 1;
            count++;
        }
        else if (isalpha(c)) {
            int start = i;
            while (isalpha(c)) {
                i++;
                c = src[i];
            }
            int end = i;
            int len = end - start;
            char *word = malloc(len + 1);
            memcpy(word, &src[start], len);
            word[len] = '\0';
            tokens = realloc(tokens, sizeof(Token) * (count + 1));
            tokens[count].type = VAR;
            tokens[count].text = word;
            tokens[count].line = 1;
            count++;
        }

        if (c == ' ') {
            i++;
        }
        else if (c == '\0') {
            continue;
        }
        else {
            printf("Error: No space between tokens\n");
            exit(EXIT_FAILURE);
        }
    }

    *out_count = count;
    return tokens;
}
