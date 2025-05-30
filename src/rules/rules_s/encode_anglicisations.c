#include "rules/rules_s/encode_anglicisations.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_Anglicisations(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // german & anglicisations, e.g. 'smith' match 'schmidt', 'snider' match
  // 'schneider' also, -sz- in slavic language altho in hungarian it is
  // pronounced 's'
  if (((m_current == 0) &&
       StringAt(w, (m_current + 1), 1, "M", "N", "L", "")) ||
      StringAt(w, (m_current + 1), 1, "Z", "")) {
    MetaphAddAlt(ctx, "S", "X");

    // eat redundant 'Z'
    if (StringAt(w, (m_current + 1), 1, "Z", "")) {
      ctx->m_current += 2;
    } else {
      ctx->m_current++;
    }

    return true;
  }

  return false;
}