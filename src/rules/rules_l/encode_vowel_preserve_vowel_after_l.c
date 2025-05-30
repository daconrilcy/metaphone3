#include "rules/rules_l/encode_vowel_preserve_vowel_after_l.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/skip_vowels.h"
#include "utils/string_utils.h"

bool Encode_Vowel_Preserve_Vowel_After_L(Metaphone3 *ctx, int save_current) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  // an example of where the vowel would NOT need to be preserved
  // would be, say, "hustled", where there is no vowel pronounced
  // between the 'l' and the 'd'
  if (ctx->m_encodeVowels && !IsVowel(CharAt(w, w, (save_current - 1))) &&
      (CharAt(w, save_current + 1) == 'E') && (save_current > 1) &&
      ((save_current + 1) != m_last) &&
      !(StringAt(w, (save_current + 1), 2, "ES", "ED", "") &&
        ((save_current + 2) == m_last)) &&
      !StringAt(w, (save_current - 1), 5, "RLEST", "")) {
    MetaphAdd(ctx, "LA");
    ctx->m_current = SkipVowels(ctx, m_current);
    return true;
  }

  return false;
}