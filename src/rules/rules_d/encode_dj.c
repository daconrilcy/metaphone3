#include "rules/rules_d/encode_dj.h"
#include "utils/metaph_add.h"

bool Encode_DJ(Metaphone3 *ctx) {
  if (StringAt(ctx->m_inWord, ctx->m_current, 2, "DJ", "")) {
    MetaphAdd(ctx, "J");
    ctx->m_current += 2;
    return true;
  }

  return false;
}