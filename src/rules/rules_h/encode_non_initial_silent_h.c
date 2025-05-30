#include "rules/rules_h/encode_non_initial_silent_h.h"
#include "utils/skip_vowels.h"
#include "utils/string_utils.h"

bool Encode_Non_Initial_Silent_H(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // exceptions - 'h' not pronounced
  //  "PROHIB" BUT NOT "PROHIBIT"
  if (StringAt(w, (m_current - 2), 5, "NIHIL", "VEHEM", "LOHEN", "NEHEM",
               "MAHON", "MAHAN", "COHEN", "GAHAN", "") ||
      StringAt(w, (m_current - 3), 6, "GRAHAM", "PROHIB", "FRAHER", "TOOHEY",
               "TOUHEY", "") ||
      StringAt(w, (m_current - 3), 5, "TOUHY", "") ||
      StringAt(w, 0, 9, "CHIHUAHUA", "")) {
    if (!ctx->m_encodeVowels) {
      ctx->m_current += 2;
    } else {
      ctx->m_current++;
      // don't encode vowels twice
      ctx->m_current = SkipVowels(ctx, m_current);
    }
    return true;
  }

  return false;
}