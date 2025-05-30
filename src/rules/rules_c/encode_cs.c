#include "rules/rules_c/encode_cs.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_CS(Metaphone3 *ctx) {
  int cur = ctx->m_current;
  int last = ctx->m_last;
  const char *w = ctx->m_inWord;

  // Cas "KOVACS" (début de mot)
  if (StringAt(w, 0, 6, "KOVACS", "")) {
    MetaphAddAlt(ctx, "KS", "X");
    ctx->m_current += 2;
    return true;
  }

  // Cas "ACS" en fin de mot, sauf "ISAACS"
  if ((cur >= 1 ? StringAt(w, cur - 1, 3, "ACS", "") : false) &&
      ((cur + 1) == last) &&
      (cur >= 4 ? !StringAt(w, cur - 4, 6, "ISAACS", "") : true)) {
    MetaphAdd(ctx, "X");
    ctx->m_current += 2;
    return true;
  }

  return false;
}
