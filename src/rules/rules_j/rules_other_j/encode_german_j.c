#include "rules/rules_j/rules_other_j/encode_german_j.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_German_J(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;
  int m_length = ctx->m_length;

  if (StringAt(w, (m_current + 1), 2, "AH", "") ||
      (StringAt(w, (m_current + 1), 5, "OHANN", "") &&
       ((m_current + 5) == m_last)) ||
      (StringAt(w, (m_current + 1), 3, "UNG", "") &&
       !StringAt(w, (m_current + 1), 4, "UNGL", "")) ||
      StringAt(w, (m_current + 1), 3, "UGO", "")) {
    MetaphAdd(ctx, "A");
    AdvanceCounter(ctx, 2, 1);
    return true;
  }

  return false;
}