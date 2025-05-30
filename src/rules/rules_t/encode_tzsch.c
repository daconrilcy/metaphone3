#include "rules/rules_t/encode_tzsch.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_TZSCH(Metaphone3 *ctx) {
  //'neitzsche'
  if (StringAt(ctx->m_inWord, ctx->m_current, 5, "TZSCH", "")) {
    MetaphAdd(ctx, "X");
    ctx->m_current += 5;
    return true;
  }

  return false;
}