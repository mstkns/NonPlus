#include <string.h>
#include <ctype.h>
#include "lexer.h"

Lexer new_lexer (const char *content) {
   Lexer l = {
      .content        = content,
      .content_length = strlen (content),
      .cursor         = 0
   };
   return l;
}

Token next_token (Lexer *l) {

   // Skip whitespace
   while (l->cursor < l->content_length && isspace (l->content [l->cursor])) {
      l->cursor++;
   }

   Token t = {
      .name  = UNKNOWN,
      .value = &l->content [l->cursor],
      .length = 0
   };

   if (isdigit (l->content [l->cursor])) {
      t.name = LITERAL;
      l->cursor++;
      t.length++;
      while (isdigit (l->content [l->cursor])) {
         l->cursor++;
         t.length++;
      }
   }
   
   return t;

}
