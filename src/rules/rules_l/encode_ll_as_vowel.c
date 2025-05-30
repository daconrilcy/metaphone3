#include "rules/rules_l/encode_ll_as_vowel.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_LL_As_Vowel(Metaphone3 *ctx) {
  // spanish e.g. "cabrillo", "gallegos" but also "gorilla", "ballerina" -
  //  give both pronounciations since an american might pronounce "cabrillo"
  //  in the spanish or the american fashion.

  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;
  int m_length = ctx->m_length;

  if ((((m_current + 3) == m_length) &&
       StringAt(w, (m_current - 1), 4, "ILLO", "ILLA", "ALLE", "")) ||
      (((StringAt(w, (m_last - 1), 2, "AS", "OS", "") ||
         StringAt(w, m_last, 2, "AS", "OS", "") ||
         StringAt(w, m_last, 1, "A", "O", "")) &&
        StringAt(w, (m_current - 1), 2, "AL", "IL", "")) &&
       !StringAt(w, (m_current - 1), 4, "ALLA", "")) ||
      StringAt(w, 0, 5, "VILLE", "VILLA", "") ||
      StringAt(w, 0, 8, "GALLARDO", "VALLADAR", "MAGALLAN", "CAVALLAR",
               "BALLASTE", "") ||
      StringAt(w, 0, 3, "LLA", "")) {
    MetaphAddAlt(ctx, "L", "");
    ctx->m_current += 2;
    return true;
  }
  return false;
}