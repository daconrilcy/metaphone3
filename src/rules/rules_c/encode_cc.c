#include "rules/rules_c/encode_cc.h"
#include "utils/advance_counter.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_CC(Metaphone3 *ctx) {
  int cur = ctx->m_current;
  int last = ctx->m_last;
  const char *w = ctx->m_inWord;

  // Double C, mais pas "McClellan"
  if (StringAt(w, cur, 2, "CC", "") && !((cur == 1) && (CharAt(w, 0) == 'M'))) {

    // Exception : "FLACCID"
    if (cur >= 3 && StringAt(w, cur - 3, 7, "FLACCID", "")) {
      MetaphAdd(ctx, "S");
      AdvanceCounter(ctx, 3, 2);
      return true;
    }

    // Cas italien : bacci, bertucci, ...
    if (((cur + 2 == last) && StringAt(w, cur + 2, 1, "I", "")) ||
        StringAt(w, cur + 2, 2, "IO", "") ||
        ((cur + 4 == last) && StringAt(w, cur + 2, 3, "INO", "INI", ""))) {
      MetaphAdd(ctx, "X");
      AdvanceCounter(ctx, 3, 2);
      return true;
    }

    // "accident", "accede", "succeed"
    if (StringAt(w, cur + 2, 1, "I", "E", "Y", "") &&
        !((CharAt(w, cur + 2) == 'H') ||
          (cur >= 2 && StringAt(w, cur - 2, 6, "SOCCER", "")))) {
      MetaphAdd(ctx, "KS");
      AdvanceCounter(ctx, 3, 2);
      return true;
    } else {
      // Règle par défaut
      MetaphAdd(ctx, "K");
      ctx->m_current += 2;
      return true;
    }
  }

  return false;
}
