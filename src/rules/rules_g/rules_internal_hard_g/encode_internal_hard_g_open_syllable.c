#include "rules/rules_g/rules_internal_hard_g/encode_internal_hard_g_open_syllable.h"
#include "utils/string_utils.h"

bool Internal_Hard_G_Open_Syllable(Metaphone3 *ctx)
{
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;
  const char *w = ctx->m_inWord;

  if (StringAt(w, (m_current + 1), 3, "EYE", "") ||
      StringAt(w, (m_current - 2), 4, "FOGY", "POGY", "YOGI", "") ||
      StringAt(w, (m_current - 2), 5, "MAGEE", "MCGEE", "HAGIO", "") ||
      StringAt(w, (m_current - 1), 4, "RGEY", "OGEY", "") ||
      StringAt(w, (m_current - 3), 5, "HOAGY", "STOGY", "PORGY", "") ||
      StringAt(w, (m_current - 5), 8, "CARNEGIE", "") ||
      (StringAt(w, (m_current - 1), 4, "OGEY", "OGIE", "") &&
       ((m_current + 2) == m_last)))
  {
    return true;
  }

  return false;
}