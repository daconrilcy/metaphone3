#include "rules/rules_g/encode_ga_to_j.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_GA_To_J(Metaphone3 *ctx) {
  int m_current = ctx->m_current;
  const char *w = ctx->m_inWord;

  // 'margary', 'margarine'
  if ((StringAt(w, (m_current - 3), 7, "MARGARY", "MARGARI", "")
       // but not in spanish forms such as "margatita"
       && !StringAt(w, (m_current - 3), 8, "MARGARIT", "")) ||
      StringAt(w, 0, 4, "GAOL", "") ||
      StringAt(w, (m_current - 2), 5, "ALGAE", "")) {
    MetaphAddExactApprox(ctx, "J", "G", "J", "K");
    AdvanceCounter(ctx, 2, 1);
    return true;
  }

  return false;
}