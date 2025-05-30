#include "rules/rules_c/encode_silent_c.h"
#include "utils/string_utils.h"

bool Encode_Silent_C(Metaphone3 *ctx) {
  int cur = ctx->m_current;
  const char *w = ctx->m_inWord;

  if (StringAt(w, cur + 1, 1, "T", "S", "")) {
    if (StringAt(w, 0, 11, "CONNECTICUT", "") ||
        StringAt(w, 0, 6, "INDICT", "TUCSON", "")) {
      ctx->m_current++;
      return true;
    }
  }
  return false;
}
