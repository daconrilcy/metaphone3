#include "rules/rules_c/rules_ch/encode_ch_to_h.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_CH_To_H(Metaphone3 *ctx) {
  int cur = ctx->m_current;
  // Translittérations hébraïques et nom irlandais
  bool found = false;
  if (cur == 0) {
    found =
        StringAt(ctx->m_inWord, cur + 2, 3, "AIM", "ETH", "ELM", "") ||
        StringAt(ctx->m_inWord, cur + 2, 4, "ASID", "AZAN", "") ||
        StringAt(ctx->m_inWord, cur + 2, 5, "UPPAH", "UTZPA", "ALLAH", "ALUTZ",
                 "AMETZ", "") ||
        StringAt(ctx->m_inWord, cur + 2, 6, "ESHVAN", "ADARIM", "ANUKAH", "") ||
        StringAt(ctx->m_inWord, cur + 2, 7, "ALLLOTH", "ANNUKAH", "AROSETH",
                 "");
  }
  if (!found && cur >= 3) {
    found = StringAt(ctx->m_inWord, cur - 3, 7, "CLACHAN", "");
  }
  if (found) {
    MetaphAdd(ctx, "H");
    AdvanceCounter(ctx, 3, 2);
    return true;
  }
  return false;
}
