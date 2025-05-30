#include "rules/rules_p/encode_rps.h"
#include "utils/string_utils.h"

bool Encode_RPS(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  //'-corps-', 'corpsman'
  if (StringAt(w, (m_current - 3), 5, "CORPS", "") &&
      !StringAt(w, (m_current - 3), 6, "CORPSE", "")) {
    ctx->m_current += 2;
    return true;
  }

  return false;
}