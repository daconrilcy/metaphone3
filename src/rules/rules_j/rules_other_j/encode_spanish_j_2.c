#include "rules/rules_j/rules_other_j/encode_spanish_j_2.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_Spanish_J_2(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;
  int m_length = ctx->m_length;

  // spanish forms e.g. "brujo", "badajoz"
  if ((((m_current - 2) == 0) &&
       StringAt(w, (m_current - 2), 4, "BOJA", "BAJA", "BEJA", "BOJO", "MOJA",
                "MOJI", "MEJI", "")) ||
      (((m_current - 3) == 0) &&
       StringAt(w, (m_current - 3), 5, "FRIJO", "BRUJO", "BRUJA", "GRAJE",
                "GRIJA", "LEIJA", "QUIJA", "")) ||
      (((m_current + 3) == m_last) &&
       StringAt(w, (m_current - 1), 5, "AJARA", "")) ||
      (((m_current + 2) == m_last) &&
       StringAt(w, (m_current - 1), 4, "AJOS", "EJOS", "OJAS", "OJOS", "UJON",
                "AJOZ", "AJAL", "UJAR", "EJON", "EJAN", "")) ||
      (((m_current + 1) == m_last) &&
       (StringAt(w, (m_current - 1), 3, "OJA", "EJA", "") &&
        !StringAt(w, 0, 4, "DEJA", "")))) {
    MetaphAdd(ctx, "H");
    AdvanceCounter(ctx, 2, 1);
    return true;
  }

  return false;
}