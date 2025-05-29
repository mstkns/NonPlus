#ifndef TOKEN_H
#define TOKEN_H

#include <stdint.h>

typedef enum {
   LITERAL,
   CONTROL,
   UNKNOWN
} Token_Name;

typedef struct {
   Token_Name name;
   const char *value;
   uint8_t length;
} Token;

char *string (Token_Name name);

void display (Token t);

#endif // TOKEN_H
