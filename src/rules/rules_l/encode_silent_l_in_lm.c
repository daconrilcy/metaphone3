#include "rules/rules_l/encode_silent_l_in_lm.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_Silent_L_In_LM(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  if (StringAt(w, m_current, 2, "LM", "LN", "")) {
    // e.g. "lincoln", "holmes", "psalm", "salmon"
    if ((StringAt(w, (m_current - 2), 4, "COLN", "CALM", "BALM", "MALM", "PALM",
                  "") ||
         (StringAt(w, (m_current - 1), 3, "OLM", "") &&
          ((m_current + 1) == m_last)) ||
         StringAt(w, (m_current - 3), 5, "PSALM", "QUALM", "") ||
         StringAt(w, (m_current - 2), 6, "SALMON", "HOLMES", "") ||
         StringAt(w, (m_current - 1), 6, "ALMOND", "") ||
         ((m_current == 1) && StringAt(w, (m_current - 1), 4, "ALMS", ""))) &&
        (!StringAt(w, (m_current + 2), 1, "A", "") &&
         !StringAt(w, (m_current - 2), 5, "BALMO", "") &&
         !StringAt(w, (m_current - 2), 6, "PALMER", "PALMOR", "BALMER", "") &&
         !StringAt(w, (m_current - 3), 5, "THALM", ""))) {
      ctx->m_current++;
      return true;
    } else {
      MetaphAdd(ctx, "L");
      ctx->m_current++;
      return true;
    }
  }

  return false;
}