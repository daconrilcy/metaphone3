#include "rules/rules_b.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"
#include <stddef.h>

bool Encode_Silent_B(const char *w, int cur, Metaphone3 *ctx) {
  // 'debt', 'doubt', 'subtle'
  if (StringAt(w, cur - 2, 4, "DEBT", "") ||
      StringAt(w, cur - 2, 5, "SUBTL", "") ||
      StringAt(w, cur - 2, 6, "SUBTIL", "") ||
      StringAt(w, cur - 3, 5, "DOUBT", "")) {
    MetaphAdd(ctx, "T");
    ctx->m_current += 2;
    return true;
  }
  return false;
}

void Encode_B(Metaphone3 *ctx) {
  int cur = ctx->m_current;
  int last = ctx->m_last;
  const char *w = ctx->m_inWord;

  if (Encode_Silent_B(w, cur, ctx)) {
    return;
  }

  // "-mb", e.g., "dumb" : déjà traité sous 'M', mais on suit la logique Java
  MetaphAddExactApproxSimple(ctx, "B", "P");

  // Vérifie la logique d’incrément selon les caractères suivants
  if ((CharAt(w, cur + 1) == 'B') ||
      ((CharAt(w, cur + 1) == 'P') &&
       ((cur + 1 < last) && (CharAt(w, cur + 2) != 'H')))) {
    ctx->m_current += 2;
  } else {
    ctx->m_current++;
  }
}
