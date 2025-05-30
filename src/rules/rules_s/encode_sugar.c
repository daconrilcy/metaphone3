#include "rules/rules_s/encode_sugar.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_Sugar(Metaphone3 *ctx) {
  // special case 'sugar-'
  if (StringAt(ctx->m_inWord, ctx->m_current, 5, "SUGAR", "")) {
    MetaphAdd(ctx, "X");
    ctx->m_current++;
    return true;
  }

  return false;
}