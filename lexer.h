#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>

typedef struct {
   const char *content;
   const size_t content_length;
   size_t cursor;
} Lexer;

Lexer new_lexer (const char *content);

#endif // LEXER_H
