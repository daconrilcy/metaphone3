#include "rules/rules_c/encode_ck_cg_cq.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_CK_CG_CQ(Metaphone3 *ctx) {
  int cur = ctx->m_current;
  int last = ctx->m_last;
  int len = ctx->m_length;
  const char *w = ctx->m_inWord;

  if (StringAt(w, cur, 2, "CK", "CG", "CQ", "")) {
    // Spelling de l’Europe de l’est : ex "gorecki"
    if (StringAt(w, cur, 3, "CKI", "CKY", "") && ((cur + 2) == last) &&
        (len > 6)) {
      MetaphAddAlt(ctx, "K", "SK");
    } else {
      MetaphAdd(ctx, "K");
    }
    ctx->m_current += 2;

    // Sauter un éventuel K, G ou Q derrière
    if (StringAt(w, ctx->m_current, 1, "K", "G", "Q", "")) {
      ctx->m_current++;
    }
    return true;
  }

  return false;
}
