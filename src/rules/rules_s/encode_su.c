#include "rules/rules_s/encode_su.h"
#include "utils/advance_counter.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_SU(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  //'sensuous', 'consensual'
  if (StringAt(w, (m_current + 1), 2, "UO", "UA", "") && (m_current != 0)) {
    // exceptions e.g. "persuade"
    if (StringAt(w, (m_current - 1), 4, "RSUA", "")) {
      MetaphAdd(ctx, "S");
    }
    // exceptions e.g. "casual"
    else if (IsVowel(CharAt(w, (m_current - 1)))) {
      MetaphAddAlt(ctx, "J", "S");
    } else {
      MetaphAddAlt(ctx, "X", "S");
    }

    AdvanceCounter(ctx, 3, 1);
    return true;
  }

  return false;
}