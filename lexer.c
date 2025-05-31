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
   while (l->cursor < l->content_length && isspace (l -> content [l -> cursor])) {
      l->cursor++;
   }

   // Initialize token
   Token t = {
      .name   = UNKNOWN,
      .value  = &l->content [l->cursor],
      .length = 0
   };

   // Handle null terminator
   if (l->content [l->cursor] == '\0') {
      t.name = CONTROL;
      l->cursor++;
      t.length++;
      return t;
   } 

   // Handle integer literal
   if (isdigit (l->content [l->cursor])) {
      t.name = LITERAL;
      l->cursor++;
      t.length++;
      while (isdigit (l->content [l->cursor])) {
         l->cursor++;
         t.length++;
      }
      return t;
   }

   // Handle string literal
   if (l->content [l->cursor] == '"') {
      l->cursor++;
      t.value++; // Skip quotation mark
      while (l->cursor < l->content_length) {
         l->cursor++;
         t.length++;
         if (l->content [l->cursor] == '"') {
            t.name = LITERAL;
            l->cursor++;
            break;
         }
      }
      return t;
   }

   // Handle identifier
   if (isalpha (l->content [l->cursor]) || l->content [l->cursor] == '_') {
      t.name = IDENTIFIER;
      l->cursor++;
      t.length++;
      while (isalnum (l->content [l->cursor]) || l->content [l->cursor] == '_') {
         l->cursor++;
         t.length++;
      }
      return t;      
   }

   return t; 

}

void display_all_tokens (Lexer *l) {
   while (l->cursor < l->content_length) {
      display (next_token (l));
   }
}
