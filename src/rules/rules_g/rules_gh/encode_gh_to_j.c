#include "rules/rules_g/rules_gh/encode_gh_to_j.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_GH_To_J(Metaphone3 *ctx) {
  // e.g., 'greenhalgh', 'dunkenhalgh', english names
  if (StringAt(ctx->m_inWord, (ctx->m_current - 2), 4, "ALGH", "") &&
      ((ctx->m_current + 1) == ctx->m_last)) {
    MetaphAddAlt(ctx, "J", "");
    ctx->m_current += 2;
    return true;
  }

  return false;
}