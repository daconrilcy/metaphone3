#include "rules/rules_j/encode_spanish_oj_uj.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_Spanish_OJ_UJ(Metaphone3 *ctx) {
  if (StringAt(ctx->m_inWord, (ctx->m_current + 1), 5, "OJOBA", "UJUY ", "")) {
    if (ctx->m_encodeVowels) {
      MetaphAdd(ctx, "HAH");
    } else {
      MetaphAdd(ctx, "HH");
    }

    AdvanceCounter(ctx, 4, 3);
    return true;
  }

  return false;
}