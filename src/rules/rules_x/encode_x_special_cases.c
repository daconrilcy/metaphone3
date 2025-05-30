#include "rules/rules_x/encode_x_special_cases.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_X_Special_Cases(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // 'luxury'
  if (StringAt(w, (m_current - 2), 5, "LUXUR", "")) {
    MetaphAddExactApproxSimple(ctx, "GJ", "KJ");
    ctx->m_current++;
    return true;
  }

  // 'texeira' portuguese/galician name
  if (StringAt(w, 0, 7, "TEXEIRA", "") || StringAt(w, 0, 8, "TEIXEIRA", "")) {
    MetaphAdd(ctx, "X");
    ctx->m_current++;
    return true;
  }

  return false;
}