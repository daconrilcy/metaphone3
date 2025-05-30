#include "rules/rules_s/encode_ss.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_SS(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // e.g. "russian", "pressure"
  if (StringAt(w, (m_current - 1), 5, "USSIA", "ESSUR", "ISSUR", "ISSUE", "")
      // e.g. "hessian", "assurance"
      || StringAt(w, (m_current - 1), 6, "ESSIAN", "ASSURE", "ASSURA", "ISSUAB",
                  "ISSUAN", "ASSIUS", "")) {
    MetaphAdd(ctx, "X");
    AdvanceCounter(ctx, 3, 2);
    return true;
  }

  return false;
}