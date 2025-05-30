#include "rules/rules_c/rules_ch/encode_silent_ch.h"
#include "utils/string_utils.h"

// Ne fait rien, saute "-CH-"
bool Encode_Silent_CH(Metaphone3 *ctx) {
  int cur = ctx->m_current;
  if (StringAt(ctx->m_inWord, cur - 2, 7, "FUCHSIA", "") ||
      StringAt(ctx->m_inWord, cur - 2, 5, "YACHT", "") ||
      StringAt(ctx->m_inWord, 0, 8, "STRACHAN", "") ||
      StringAt(ctx->m_inWord, 0, 8, "CRICHTON", "") ||
      (StringAt(ctx->m_inWord, cur - 3, 6, "DRACHM", "") &&
       !StringAt(ctx->m_inWord, cur - 3, 7, "DRACHMA", ""))) {
    ctx->m_current += 2;
    return true;
  }
  return false;
}