#include "rules/rules_c/rules_ch/encode_ch_to_x.h"
#include "buffer.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_CH_To_X(Metaphone3 *ctx) {
  int cur = ctx->m_current, last = ctx->m_last;

  // On protège chaque accès à m_current - X (ne pas envoyer des indices
  // négatifs à StringAt)
  if (((cur >= 2 && StringAt(ctx->m_inWord, cur - 2, 4, "OACH", "EACH", "EECH",
                             "OUCH", "OOCH", "MUCH", "SUCH", "")) &&
       !(cur >= 3 && StringAt(ctx->m_inWord, cur - 3, 5, "JOACH", ""))) ||
      (((cur + 2) == last) && cur >= 1 &&
       StringAt(ctx->m_inWord, cur - 1, 4, "ACHA", "ACHO", "")) ||
      ((cur + 3 == last) &&
       StringAt(ctx->m_inWord, cur, 4, "CHOT", "CHOD", "CHAT", "")) ||
      ((cur >= 1 && StringAt(ctx->m_inWord, cur - 1, 4, "OCHE", "")) &&
       (cur + 2 == last) &&
       !(cur >= 2 && StringAt(ctx->m_inWord, cur - 2, 5, "DOCHE", ""))) ||
      (cur >= 4 &&
       StringAt(ctx->m_inWord, cur - 4, 6, "ATTACH", "DETACH", "KOVACH", "")) ||
      (cur >= 5 && StringAt(ctx->m_inWord, cur - 5, 7, "SPINACH", "")) ||
      StringAt(ctx->m_inWord, 0, 6, "MACHAU", "") ||
      (cur >= 4 && StringAt(ctx->m_inWord, cur - 4, 8, "PARACHUT", "")) ||
      (cur >= 5 && StringAt(ctx->m_inWord, cur - 5, 8, "MASSACHU", "")) ||
      (cur >= 3 && StringAt(ctx->m_inWord, cur - 3, 5, "THACH", "") &&
       !(cur >= 1 && StringAt(ctx->m_inWord, cur - 1, 4, "ACHE", ""))) ||
      (cur >= 2 && StringAt(ctx->m_inWord, cur - 2, 6, "VACHON", ""))) {
    MetaphAdd(ctx, "X");
    ctx->m_current += 2;
    return true;
  }
  return false;
}
