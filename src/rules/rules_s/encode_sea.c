#include "rules/rules_s/encode_sea.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_SEA(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  if ((StringAt(w, 0, 4, "SEAN", "") && ((m_current + 3) == m_last)) ||
      (StringAt(w, (m_current - 3), 6, "NAUSEO", "") &&
       !StringAt(w, (m_current - 3), 7, "NAUSEAT", ""))) {
    MetaphAdd(ctx, "X");
    AdvanceCounter(ctx, 3, 1);
    return true;
  }

  return false;
}