#include <stdio.h>
#include "token.h"

// TODO: Extend this once more token names are added
char *string (Token_Name name) {
   switch (name) {
      case LITERAL: return "LITERAL";
      case CONTROL: return "CONTROL";
      case UNKNOWN: return "UNKNOWN";
   }
}

void display (Token t) {
   printf ("(%s, %.*s)\n", string (t.name), t.length, t.value);
}
