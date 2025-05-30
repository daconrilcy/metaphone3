#include "rules/rules_l/encode_lely_to_l.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_LELY_To_L(Metaphone3 *ctx) {
  // e.g. "agilely", "docilely"
  if (StringAt(ctx->m_inWord, (ctx->m_current - 1), 5, "ILELY", "") &&
      ((ctx->m_current + 3) == ctx->m_last)) {
    MetaphAdd(ctx, "L");
    ctx->m_current += 3;
    return true;
  }

  return false;
}