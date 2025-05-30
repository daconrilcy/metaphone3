#include "rules/rules_g/encode_hard_ge_at_end.h"
#include "utils/string_utils.h"

bool Hard_GE_At_End(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;

  if (StringAt(w, 0, 6, "RENEGE", "STONGE", "STANGE", "PRANGE", "KRESGE", "") ||
      StringAt(w, 0, 5, "BYRGE", "BIRGE", "BERGE", "HAUGE", "") ||
      StringAt(w, 0, 4, "HAGE", "") ||
      StringAt(w, 0, 5, "LANGE", "SYNGE", "BENGE", "RUNGE", "HELGE", "") ||
      StringAt(w, 0, 4, "INGE", "LAGE", "")) {
    return true;
  }

  return false;
}