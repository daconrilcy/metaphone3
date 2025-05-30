#include "rules/rules_n.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_NCE(Metaphone3 *ctx) {
  //'acceptance', 'accountancy'
  if (StringAt(ctx->m_inWord, (ctx->m_current + 1), 1, "C", "S", "") &&
      StringAt(ctx->m_inWord, (ctx->m_current + 2), 1, "E", "Y", "I", "") &&
      (((ctx->m_current + 2) == ctx->m_last) ||
       (((ctx->m_current + 3) == ctx->m_last)) &&
           (CharAt(ctx->m_inWord, (ctx->m_current + 3)) == 'S'))) {
    MetaphAdd(ctx, "NTS");
    ctx->m_current += 2;
    return true;
  }

  return false;
}

void Encode_N(Metaphone3 *ctx) {
  if (Encode_NCE(ctx)) {
    return;
  }

  // eat redundant 'N'
  if (CharAt(ctx->m_inWord, (ctx->m_current + 1)) == 'N') {
    ctx->m_current += 2;
  } else {
    ctx->m_current++;
  }

  if (!StringAt((ctx->m_inWord, ctx->m_current - 3), 8, "MONSIEUR", "")
      // e.g. "aloneness",
      && !StringAt((ctx->m_inWord, ctx->m_current - 3), 6, "NENESS", "")) {
    MetaphAdd(ctx, "N");
  }
}