#ifndef TOKEN_H
#define TOKEN_H

#include <stdint.h>

typedef enum {
   LITERAL
} Token_Name;

char *string (Token_Name name);

typedef struct {
   Token_Name name;
   const char *value;
   uint8_t length;
} Token;

#endif // TOKEN_H
