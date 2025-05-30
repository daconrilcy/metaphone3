#include "rules/rules_p/encode_pt.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_PT(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // 'pterodactyl', 'receipt', 'asymptote'
  if ((CharAt(w, (m_current + 1)) == 'T')) {
    if (((m_current == 0) && StringAt(w, m_current, 5, "PTERO", "")) ||
        StringAt(w, (m_current - 5), 7, "RECEIPT", "") ||
        StringAt(w, (m_current - 4), 8, "ASYMPTOT", "")) {
      MetaphAdd(ctx, "T");
      ctx->m_current += 2;
      return true;
    }
  }
  return false;
}