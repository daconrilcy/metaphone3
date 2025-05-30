#include "rules/rules_m/rules_mb/test_pronounced_mb.h"
#include "utils/string_utils.h"

bool Test_Pronounced_MB(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  if (StringAt(w, (m_current - 2), 6, "NUMBER", "") ||
      (StringAt(w, (m_current + 2), 1, "A", "") &&
       !StringAt(w, (m_current - 2), 7, "DUMBASS", "")) ||
      StringAt(w, (m_current + 2), 1, "O", "") ||
      StringAt(w, (m_current - 2), 6, "LAMBEN", "LAMBER", "LAMBET", "TOMBIG",
               "LAMBRE", "")) {
    return true;
  }

  return false;
}