#include "rules/rules_q.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

void Encode_Q(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // current pinyin
  if (StringAt(w, m_current, 3, "QIN", "")) {
    MetaphAdd(ctx, "X");
    ctx->m_current++;
    return;
  }

  // eat redundant 'Q'
  if (CharAt(w, (m_current + 1)) == 'Q') {
    ctx->m_current += 2;
  } else {
    ctx->m_current++;
  }

  MetaphAdd(ctx, "K");
}