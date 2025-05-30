#include "rules/rules_l/encode_ll_as_vowel_cases.h"
#include "rules/rules_l/encode_ll_as_vowel.h"
#include "rules/rules_l/encode_ll_as_vowel_special_cases.h"

#include "utils/string_utils.h"

bool Encode_LL_As_Vowel_Cases(Metaphone3 *ctx) {
  if (CharAt(ctx->m_inWord, (ctx->m_current + 1)) == 'L') {
    if (Encode_LL_As_Vowel_Special_Cases(ctx)) {
      return true;
    } else if (Encode_LL_As_Vowel(ctx)) {
      return true;
    }
    ctx->m_current += 2;
  } else {
    ctx->m_current++;
  }

  return false;
}