#include "rules/rules_m/encode_mac.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_MAC(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // should only find irish and
  // scottish names e.g. 'macintosh'
  if ((m_current == 0) &&
      (StringAt(w, 0, 7, "MACIVER", "MACEWEN", "") ||
       StringAt(w, 0, 8, "MACELROY", "MACILROY", "") ||
       StringAt(w, 0, 9, "MACINTOSH", "") || StringAt(w, 0, 2, "MC", ""))) {
    if (ctx->m_encodeVowels) {
      MetaphAdd(ctx, "MAK");
    } else {
      MetaphAdd(ctx, "MK");
    }

    if (StringAt(w, 0, 2, "MC", "")) {
      if (StringAt(w, (m_current + 2), 1, "K", "G", "Q", "")
          // watch out for e.g. "McGeorge"
          && !StringAt(w, (m_current + 2), 4, "GEOR", "")) {
        ctx->m_current += 3;
      } else {
        ctx->m_current += 2;
      }
    } else {
      ctx->m_current += 3;
    }

    return true;
  }

  return false;
}