#include "rules/rules_s/encode_sur.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_SUR(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // 'erasure', 'usury'
  if (StringAt(w, (m_current + 1), 3, "URE", "URA", "URY", "")) {
    //'sure', 'ensure'
    if ((m_current == 0) || StringAt(w, (m_current - 1), 1, "N", "K", "") ||
        StringAt(w, (m_current - 2), 2, "NO", "")) {
      MetaphAdd(ctx, "X");
    } else {
      MetaphAdd(ctx, "J");
    }

    AdvanceCounter(ctx, 2, 1);
    return true;
  }

  return false;
}