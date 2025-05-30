#include "rules/rules_c/encode_cz.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_CZ(Metaphone3 *ctx) {
  int cur = ctx->m_current;
  const char *w = ctx->m_inWord;

  if (StringAt(w, cur + 1, 1, "Z", "") &&
      (cur >= 1 ? !StringAt(w, cur - 1, 6, "ECZEMA", "") : true)) {
    if (StringAt(w, cur, 4, "CZAR", "")) {
      MetaphAdd(ctx, "S");
    } else {
      MetaphAdd(ctx, "X");
    }
    ctx->m_current += 2;
    return true;
  }
  return false;
}
