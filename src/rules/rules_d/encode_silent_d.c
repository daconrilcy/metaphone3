#include "rules/rules_d/encode_silent_d.h"
#include "utils/string_utils.h"

bool Encode_Silent_D(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int cur = ctx->m_current;

  // silent 'D' e.g. 'wednesday', 'handsome'
  if (StringAt(w, (cur - 2), 9, "WEDNESDAY", "") ||
      StringAt(w, (cur - 3), 7, "HANDKER", "HANDSOM", "WINDSOR", "")
      // french silent D at end in words or names familiar to americans
      || StringAt(w, (cur - 5), 6, "PERNOD", "ARTAUD", "RENAUD", "") ||
      StringAt(w, (cur - 6), 7, "RIMBAUD", "MICHAUD", "BICHAUD", "")) {
    ctx->m_current++;
    return true;
  }

  return false;
}