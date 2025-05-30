#include "rules/rules_g/rules_gh/encode_gh_to_h.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_GH_To_H(Metaphone3 *ctx) {
  if ((StringAt(ctx->m_inWord, (ctx->m_current - 4), 4, "DONO", "DONA", "") &&
       IsVowel(CharAt(ctx->m_inWord, (ctx->m_current + 2)))) ||
      StringAt(ctx->m_inWord, (ctx->m_current - 5), 9, "CALLAGHAN", "")) {
    MetaphAdd(ctx, "H");
    ctx->m_current += 2;
    return true;
  }

  return false;
}