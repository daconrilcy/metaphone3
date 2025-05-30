#include "rules/rules_c/encode_silent_c_at_beginning.h"
#include "utils/string_utils.h"

bool Encode_Silent_C_At_Beginning(Metaphone3 *ctx) {
  // Si on est au début du mot et que la séquence est "CT" ou "CN"
  if (ctx->m_current == 0 &&
      StringAt(ctx->m_inWord, ctx->m_current, 2, "CT", "CN", "")) {
    ctx->m_current += 1; // Skip le C muet
    return true;
  }
  return false;
}
