#include "utils/skip_vowels.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"

#include <stdio.h>

/**
 * Saute toutes les voyelles et 'W' à partir de l'index 'at',
 * sauf pour certains patterns spécifiques (noms polonais, etc.)
 * Renvoie le nouvel index (première consonne rencontrée ou fin de chaîne).
 */
int SkipVowels(Metaphone3 *ctx, int at)
{
  int m_length = ctx->m_length;
  int m_last = ctx->m_last;
  const char *w = ctx->m_inWord;

  if (at < 0)
    return 0;
  if (at >= m_length)
    return m_length;

  char it = CharAt(w, at);
  int old_at = -1;

  while (at < m_length && (IsVowel(it) || it == 'W'))
  {
    if (at == old_at)
    {
      // Ceinture anti-boucle !
      at++; // on avance pour ne pas rester bloqué
      break;
    }
    old_at = at;
    // Cas spécifiques : noms polonais (arrêt du skip)
    if (StringAt(w, at, 4, "WICZ", "WITZ", "WIAK", "") ||
        StringAt(w, at - 1, 5, "EWSKI", "EWSKY", "OWSKI", "OWSKY", "") ||
        (StringAt(w, at, 5, "WICKI", "WACKI", "") && (at + 4 == m_last)))
    {
      break;
    }

    at++;
    if (at >= m_length)
      break;

    // Test pour le WH, mais attention à bien mettre à jour 'it'
    if ((CharAt(w, at - 1) == 'W') && (CharAt(w, at) == 'H') &&
        !(StringAt(w, at, 3, "HOP", "") ||
          StringAt(w, at, 4, "HIDE", "HARD", "HEAD", "HAWK", "HERD", "HOOK",
                   "HAND", "HOLE", "") ||
          StringAt(w, at, 5, "HEART", "HOUSE", "HOUND", "") ||
          StringAt(w, at, 6, "HAMMER", "")))
    {
      at++;
      if (at >= m_length)
        break;
    }
    // --> Met TOUJOURS à jour 'it' à la fin du tour de boucle
    it = CharAt(w, at);
  }

  return at;
}
