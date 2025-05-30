#include "rules/rules_z/encode_zu_zier_zs.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_ZU_ZIER_ZS(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  if (((m_current == 1) && StringAt(w, (m_current - 1), 4, "AZUR", "")) ||
      (StringAt(w, m_current, 4, "ZIER", "") &&
       !StringAt(w, (m_current - 2), 6, "VIZIER", "")) ||
      StringAt(w, m_current, 3, "ZSA", "")) {
    MetaphAddAlt(ctx, "J", "S");

    if (StringAt(w, m_current, 3, "ZSA", "")) {
      ctx->m_current += 2;
    } else {
      ctx->m_current++;
    }
    return true;
  }

  return false;
}