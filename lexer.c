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
            while (isalpha(c) || isdigit(c) || c == '_') {
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
        else if (c == '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == '>' || c == '<' || c == '!' || c == '%') {
            int start = i;
            int len = 1;
            if (src[i + 1] == '=') {
                len = 2;
            }
            char *word = malloc(len + 1);
            memcpy(word, &src[start], len);
            word[len] = '\0';
            tokens = realloc(tokens, sizeof(Token) * (count + 1));
            tokens[count].type = OP;
            tokens[count].text = word;
            tokens[count].line = 1;
            count++;
            i += len;
        }
        else if (c == '\n') {
            int len = 1;
            char *word = malloc(len + 1);
            memcpy(word, &src[i], len);
            word[len] = '\0';
            tokens = realloc(tokens, sizeof(Token) * (count + 1));
            tokens[count].type = END_OF_FILE;
            tokens[count].text = word;
            tokens[count].line = 1;
            count++;
            i++;
        }

        if (c == ' ') {
            i++;
        }
        else if (c == '\0') {
            continue;
        }
    }

    *out_count = count;
    return tokens;
}
