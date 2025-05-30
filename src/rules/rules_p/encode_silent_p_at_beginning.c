#include "rules/rules_p/encode_silent_p_at_beginning.h"
#include "utils/string_utils.h"

bool Encode_Silent_P_At_Beginning(Metaphone3 *ctx) {
  // skip these when at start of word
  if ((ctx->m_current == 0) &&
      StringAt(ctx->m_inWord, ctx->m_current, 2, "PN", "PF", "PS", "PT", "")) {
    ctx->m_current += 1;
    return true;
  }

  return false;
}