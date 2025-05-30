#include "rules/rules_c/encode_co_to_s.h"
#include "utils/advance_counter.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_CO_To_S(Metaphone3 *ctx) {
  int last = ctx->m_last;
  int cur = ctx->m_current;

  if (
      // "COEL", suivi d'une voyelle ou fin de mot
      (StringAt(ctx->m_inWord, cur, 4, "COEL", "") &&
       (IsVowelAt(ctx, cur + 4) || (cur + 3) == last))
      // "COENA", "COENO"
      || StringAt(ctx->m_inWord, cur, 5, "COENA", "COENO", "")
      // ou dans tout le mot
      || StringAt(ctx->m_inWord, 0, 8, "FRANCOIS", "MELANCON", "") ||
      StringAt(ctx->m_inWord, 0, 6, "GARCON", "")) {
    MetaphAdd(ctx, "S");
    AdvanceCounter(ctx, 3, 1);
    return true;
  }
  return false;
}
