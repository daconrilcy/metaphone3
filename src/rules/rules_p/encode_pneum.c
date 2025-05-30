#include "rules/rules_p/encode_pneum.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_PNEUM(Metaphone3 *ctx) {
  //'-pneum-'
  if (StringAt(ctx->m_inWord, (ctx->m_current + 1), 4, "NEUM", "")) {
    MetaphAdd(ctx, "N");
    ctx->m_current += 2;
    return true;
  }

  return false;
}