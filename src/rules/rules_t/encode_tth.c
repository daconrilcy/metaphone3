#include "rules/rules_t/encode_tth.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_TTH(Metaphone3 *ctx) {
  // 'matthew' vs. 'outthink'
  if (StringAt(ctx->m_inWord, ctx->m_current, 3, "TTH", "")) {
    if (StringAt(ctx->m_inWord, (ctx->m_current - 2), 5, "MATTH", "")) {
      MetaphAdd(ctx, "0");
    } else {
      MetaphAdd(ctx, "T0");
    }
    ctx->m_current += 3;
    return true;
  }

  return false;
}