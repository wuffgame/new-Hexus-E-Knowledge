//
// Created by wuff on 22.11.2026.
//

#ifndef NEW_HEXUS_E_KNOWLEDGE_LEXER_H
#define NEW_HEXUS_E_KNOWLEDGE_LEXER_H

typedef enum {
    OP, // 0
    VAR, // 1
    INT, // 2
    END_OF_FILE // 3
} TokenType;

typedef struct {
    TokenType type;
    char *text;
    int line;
} Token;

Token *tokenize(const char *src, int *out_count);

#endif //NEW_HEXUS_E_KNOWLEDGE_LEXER_H
