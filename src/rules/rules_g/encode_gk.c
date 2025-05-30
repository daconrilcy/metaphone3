#include "rules/rules_g/encode_gk.h"
#include "utils/metaph_add.h"

bool Encode_GK(Metaphone3 *ctx) {
  // 'gingko'
  if (CharAt(ctx->m_inWord, ctx->m_current + 1) == 'K') {
    MetaphAdd(ctx, "K");
    ctx->m_current += 2;
    return true;
  }

  return false;
}