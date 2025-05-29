#include <string.h>
#include "lexer.h"

Lexer new_lexer (const char *content) {
   Lexer l = {
      .content        = content,
      .content_length = strlen (content),
      .cursor         = 0
   };
   return l;
}
