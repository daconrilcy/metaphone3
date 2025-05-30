#include "rules/rules_t/encode_tch.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_TCH(Metaphone3 *ctx) {
  if (StringAt(ctx->m_inWord, (ctx->m_current + 1), 2, "CH", "")) {
    MetaphAdd(ctx, "X");
    ctx->m_current += 3;
    return true;
  }

  return false;
}