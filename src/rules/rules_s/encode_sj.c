#include "rules/rules_s/encode_sj.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_SJ(Metaphone3 *ctx) {
  if (StringAt(ctx->m_inWord, 0, 2, "SJ", "")) {
    MetaphAdd(ctx, "X");
    ctx->m_current += 2;
    return true;
  }

  return false;
}