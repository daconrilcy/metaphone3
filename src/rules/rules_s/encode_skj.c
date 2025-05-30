#include "rules/rules_s/encode_skj.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_SKJ(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // scandinavian
  if (StringAt(w, m_current, 4, "SKJO", "SKJU", "") &&
      IsVowel(CharAt(w, (m_current + 3)))) {
    MetaphAdd(ctx, "X");
    ctx->m_current += 3;
    return true;
  }

  return false;
}