#include "rules/rules_x/encode_initial_x.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_Initial_X(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // current chinese pinyin spelling
  if (StringAt(w, 0, 3, "XIA", "XIO", "XIE", "") ||
      StringAt(w, 0, 2, "XU", "")) {
    MetaphAdd(ctx, "X");
    ctx->m_current++;
    return true;
  }

  // else
  if ((m_current == 0)) {
    MetaphAdd(ctx, "S");
    ctx->m_current++;
    return true;
  }

  return false;
}