#include "rules/rules_j/rules_other_j/encode_j_as_vowel.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_J_As_Vowel(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;
  int m_length = ctx->m_length;

  if (StringAt(w, m_current, 5, "JEWSK", ""))
  {
    MetaphAddAlt(ctx, "J", "");
    return true;
  }

  // e.g. "stijl", "sejm" - dutch, scandanavian, and eastern european spellings
  if ((StringAt(w, (m_current + 1), 1, "L", "T", "K", "S", "N", "M", "")
       // except words from hindi and arabic
       && !StringAt(w, (m_current + 2), 1, "A", "")) ||
      StringAt(w, 0, 9, "HALLELUJA", "LJUBLJANA", "") ||
      StringAt(w, 0, 4, "LJUB", "BJOR", "") || StringAt(w, 0, 5, "HAJEK", "") ||
      StringAt(w, 0, 3, "WOJ", "")
      // e.g. 'fjord'
      || StringAt(w, 0, 2, "FJ", "")
      // e.g. 'rekjavik', 'blagojevic'
      || StringAt(w, m_current, 5, "JAVIK", "JEVIC", "") ||
      (((m_current + 1) == m_last) &&
       StringAt(w, 0, 5, "SONJA", "TANJA", "TONJA", "")))

  {
    return true;
  }
  return false;
}