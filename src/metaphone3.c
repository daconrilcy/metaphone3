#include "metaphone3.h"
#include "buffer.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---- Helpers ----
// Nettoie et met en majuscule une copie d’un mot source
static char *normalize_word(const char *word)
{
  int len = strlen(word);
  char *out = malloc(len + 1);
  if (!out)
    exit(1);
  int j = 0;
  for (int i = 0; i < len; ++i)
  {
    char c = word[i];
    if (c >= 'a' && c <= 'z')
      c -= 32; // toupper version simple
    if ((c >= 'A' && c <= 'Z'))
    {
      out[j++] = c;
    }
    // Si besoin : gérer accents ou autres caractères ici
  }
  out[j] = '\0';
  return out;
}

// ---- API ----

Metaphone3 *Metaphone3_new(const char *word, bool encodeVowels, bool encodeExact, int metaphLength)
{

  Metaphone3 *ctx = malloc(sizeof(Metaphone3));
  if (!ctx)
    exit(1);
  ctx->m_inWord = normalize_word(word);
  ctx->m_length = strlen(ctx->m_inWord);
  ctx->m_last = ctx->m_length > 0 ? ctx->m_length - 1 : 0;
  ctx->m_primary = Buffer_new(metaphLength > 0 ? metaphLength : 32);
  ctx->m_secondary = Buffer_new(metaphLength > 0 ? metaphLength : 32);
  ctx->m_metaphLength = metaphLength > 0 ? metaphLength : 32;
  ctx->m_encodeVowels = encodeVowels;
  ctx->m_encodeExact = encodeExact;
  ctx->m_current = 0;
  ctx->flag_AL_inversion = false;
  // Init autres flags si besoin
  return ctx;
}

void Metaphone3_free(Metaphone3 *ctx)
{
  if (!ctx)
    return;
  if (ctx->m_inWord)
    free(ctx->m_inWord);
  Buffer_free(ctx->m_primary);
  Buffer_free(ctx->m_secondary);
  free(ctx);
}

// ---- Accès aux résultats ----
const char *Metaphone3_primary(Metaphone3 *ctx)
{
  return ctx && ctx->m_primary ? Buffer_data(ctx->m_primary) : "";
}
const char *Metaphone3_secondary(Metaphone3 *ctx)
{
  return ctx && ctx->m_secondary ? Buffer_data(ctx->m_secondary) : "";
}