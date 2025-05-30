#include "rules/rules_s/encode_sia.h"
#include "utils/advance_counter.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_SIA(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  // e.g. "controversial", also "fuchsia", "ch" is silent
  if (StringAt(w, (m_current - 2), 5, "CHSIA", "") ||
      StringAt(w, (m_current - 1), 5, "RSIAL", "")) {
    MetaphAdd(ctx, "X");
    AdvanceCounter(ctx, 3, 1);
    return true;
  }

  // names generally get 'X' where terms, e.g. "aphasia" get 'J'
  if ((StringAt(w, 0, 6, "ALESIA", "ALYSIA", "ALISIA", "STASIA", "") &&
       (m_current == 3) && !StringAt(w, 0, 9, "ANASTASIA", "")) ||
      StringAt(w, (m_current - 5), 9, "DIONYSIAN", "") ||
      StringAt(w, (m_current - 5), 8, "THERESIA", "")) {
    MetaphAddAlt(ctx, "X", "S");
    AdvanceCounter(ctx, 3, 1);
    return true;
  }

  if ((StringAt(w, m_current, 3, "SIA", "") && ((m_current + 2) == m_last)) ||
      (StringAt(w, m_current, 4, "SIAN", "") && ((m_current + 3) == m_last)) ||
      StringAt(w, (m_current - 5), 9, "AMBROSIAL", "")) {
    if ((IsVowel(CharAt(w, (m_current - 1))) ||
         StringAt(w, (m_current - 1), 1, "R", ""))
        // exclude compounds based on names, or french or greek words
        && !(StringAt(w, 0, 5, "JAMES", "NICOS", "PEGAS", "PEPYS", "") ||
             StringAt(w, 0, 6, "HOBBES", "HOLMES", "JAQUES", "KEYNES", "") ||
             StringAt(w, 0, 7, "MALTHUS", "HOMOOUS", "") ||
             StringAt(w, 0, 8, "MAGLEMOS", "HOMOIOUS", "") ||
             StringAt(w, 0, 9, "LEVALLOIS", "TARDENOIS", "") ||
             StringAt(w, (m_current - 4), 5, "ALGES", ""))) {
      MetaphAdd(ctx, "J");
    } else {
      MetaphAdd(ctx, "S");
    }

    AdvanceCounter(ctx, 2, 1);
    return true;
  }
  return false;
}