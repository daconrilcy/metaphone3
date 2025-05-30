#include "rules/rules_c/rules_ch/encode_english_ch_to_k.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

// Tu dois définir ou intégrer RootOrInflections en C pour ce code !
extern bool RootOrInflections(const char *inWord, const char *root);

bool Encode_English_CH_To_K(Metaphone3 *ctx) {
  int cur = ctx->m_current;

  if (((cur == 1) && RootOrInflections(ctx->m_inWord, "ACHE")) ||
      ((cur > 3) && RootOrInflections(ctx->m_inWord + cur - 1, "ACHE") &&
       (StringAt(ctx->m_inWord, 0, 3, "EAR", "") ||
        StringAt(ctx->m_inWord, 0, 4, "HEAD", "BACK", "") ||
        StringAt(ctx->m_inWord, 0, 5, "HEART", "BELLY", "TOOTH", ""))) ||
      (cur >= 1 && StringAt(ctx->m_inWord, cur - 1, 4, "ECHO", "")) ||
      (cur >= 2 && StringAt(ctx->m_inWord, cur - 2, 7, "MICHEAL", "")) ||
      (cur >= 4 && StringAt(ctx->m_inWord, cur - 4, 7, "JERICHO", "")) ||
      (cur >= 5 && StringAt(ctx->m_inWord, cur - 5, 7, "LEPRECH", ""))) {
    MetaphAddAlt(ctx, "K", "X");
    ctx->m_current += 2;
    return true;
  }
  return false;
}
