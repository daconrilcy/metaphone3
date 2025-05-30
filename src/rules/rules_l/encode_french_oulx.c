#include "rules/rules_l/encode_french_oulx.h"
#include "utils/string_utils.h"

bool Encode_French_OULX(Metaphone3 *ctx)
{
  // e.g. "proulx"
  if (StringAt(ctx->m_inWord, (ctx->m_current - 2), 4, "OULX", "") &&
      ((ctx->m_current + 1) == ctx->m_last))
  {
    ctx->m_current += 2;
    return true;
  }

  return false;
}