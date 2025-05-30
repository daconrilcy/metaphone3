#include "rules/rules_r/encode_vowel_re_transposition.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"
#include "utils/char_utils.h"

bool Encode_Vowel_RE_Transposition(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_length = ctx->m_length;
  int m_last = ctx->m_last;

  // -re inversion is just like
  // -le inversion
  // e.g. "fibre" => FABAR or "centre" => SANTAR
  if ((ctx->m_encodeVowels) && (CharAt(w, (m_current + 1)) == 'E') &&
      (m_length > 3) && !StringAt(w, 0, 5, "OUTRE", "LIBRE", "ANDRE", "") &&
      !(StringAt(w, 0, 4, "FRED", "TRES", "") && (m_length == 4)) &&
      !StringAt(w, (m_current - 2), 5, "LDRED", "LFRED", "NDRED", "NFRED",
                "NDRES", "TRES", "IFRED", "") &&
      !IsVowel(CharAt(w, (m_current - 1))) &&
      (((m_current + 1) == m_last) ||
       (((m_current + 2) == m_last) &&
        StringAt(w, (m_current + 2), 1, "D", "S", ""))))
  {
    MetaphAdd(ctx, "AR");
    return true;
  }

  return false;
}