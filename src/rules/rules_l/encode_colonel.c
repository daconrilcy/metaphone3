#include "rules/rules_l/encode_colonel.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_COLONEL(Metaphone3 *ctx) {
  if (StringAt(ctx->m_inWord, (ctx->m_current - 2), 7, "COLONEL", "")) {
    MetaphAdd(ctx, "R");
    ctx->m_current += 2;
    return true;
  }

  return false;
}