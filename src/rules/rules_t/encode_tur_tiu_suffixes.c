#include "rules/rules_t/encode_tur_tiu_suffixes.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_TUR_TIU_Suffixes(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  // 'adventure', 'musculature'
  if ((m_current > 0) && StringAt(w, (m_current + 1), 3, "URE", "URA", "URI",
                                  "URY", "URO", "IUS", "")) {
    // exceptions e.g. 'tessitura', mostly from romance languages
    if ((StringAt(w, (m_current + 1), 3, "URA", "URO", "")
         //&& !StringAt(w,(m_current + 1), 4, "URIA", "")
         && ((m_current + 3) == m_last)) &&
            !StringAt(w, (m_current - 3), 7, "VENTURA", "")
        // e.g. "kachaturian", "hematuria"
        || StringAt(w, (m_current + 1), 4, "URIA", "")) {
      MetaphAdd(ctx, "T");
    } else {
      MetaphAddAlt(ctx, "X", "T");
    }

    AdvanceCounter(ctx, 2, 1);
    return true;
  }

  return false;
}