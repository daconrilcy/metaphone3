#include "rules/rules_m/rules_mb/test_silent_mb_1.h"
#include "utils/string_utils.h"

bool Test_Silent_MB_1(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // e.g. "LAMB", "COMB", "LIMB", "DUMB", "BOMB"
  // Handle combining roots first
  if (((m_current == 3) && StringAt(w, (m_current - 3), 5, "THUMB", "")) ||
      ((m_current == 2) && StringAt(w, (m_current - 2), 4, "DUMB", "BOMB",
                                    "DAMN", "LAMB", "NUMB", "TOMB", ""))) {
    return true;
  }

  return false;
}