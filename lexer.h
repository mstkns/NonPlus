#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>
#include "token.h"

typedef struct {
   const char *content;
   const size_t content_length;
   size_t cursor;
} Lexer;

Lexer new_lexer (const char *content);

Token next_token (Lexer *l);

#endif // LEXER_H
