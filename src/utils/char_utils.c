#include "utils/char_utils.h"
#include "metaphone3.h"
#include <ctype.h>
#include <stdbool.h>
#include "utils/string_utils.h"

bool IsVowel(char inChar)
{
  inChar = ToUpper(inChar);
  // Version simple, gère A, E, I, O, U, Y
  return (inChar == 'A') || (inChar == 'E') || (inChar == 'I') ||
         (inChar == 'O') || (inChar == 'U') || (inChar == 'Y');
}

bool IsConsonant(char c)
{
  c = ToUpper(c);
  return ((c >= 'A' && c <= 'Z') && !IsVowel(c));
}

char ToUpper(char c) { return (char)toupper((unsigned char)c); }

char ToLower(char c) { return (char)tolower((unsigned char)c); }

// Renvoie true si c'est une voyelle à la position idx (ou fin de mot)
bool IsVowelAt(Metaphone3 *ctx, int idx)
{
  char c = CharAt(ctx->m_inWord, idx);
  return IsVowel(c);
}
