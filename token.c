#include <stdio.h>
#include "token.h"

// TODO: Extend this once more token names are added
char *string (Token_Name name) {
   switch (name) {
      case LITERAL:    return "LITERAL";
      case IDENTIFIER: return "IDENTIFIER";
      case CONTROL:    return "CONTROL";
      case UNKNOWN:    return "UNKNOWN";
      default:         return "UNKNOWN";
   }
}

void display (Token t) {

   printf ("(%s, ", string (t.name));

   if (*t.value == '\0') {
      printf ("\\0)\n");
   } else {
      printf ("%.*s)\n", (int) t.length, t.value);   
   }
}
