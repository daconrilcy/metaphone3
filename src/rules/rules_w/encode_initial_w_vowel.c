#include "rules/rules_w/encode_initial_w_vowel.h"
#include "rules/various/germanic_or_slavic_name_beginning_with_w.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/skip_vowels.h"
#include "utils/string_utils.h"

bool Encode_Initial_W_Vowel(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;
  int m_length = ctx->m_length;

  if ((m_current == 0) && IsVowel(CharAt(w, (m_current + 1)))) {
    // Witter should match Vitter
    if (Germanic_Or_Slavic_Name_Beginning_With_W(ctx)) {
      if (ctx->m_encodeVowels) {
        MetaphAddExactApprox(ctx, "A", "VA", "A", "FA");
      } else {
        MetaphAddExactApprox(ctx, "A", "V", "A", "F");
      }
    } else {
      MetaphAdd(ctx, "A");
    }

    ctx->m_current++;
    // don't encode vowels twice
    ctx->m_current = SkipVowels(ctx, m_current);
    return true;
  }

  return false;
}