#include "rules/rules_e/encode_e_pronounced.h"
#include "rules/rules_e/e_pronounced_exceptions.h"
#include "rules/rules_e/e_silent.h"
#include "rules/rules_e/silent_internal_e.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

void Encode_E_Pronounced(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_length = ctx->m_length;

  // special cases with two pronunciations
  // 'agape' 'lame' 'resume'
  if ((StringAt(w, 0, 4, "LAME", "SAKE", "PATE", "") && (m_length == 4)) ||
      (StringAt(w, 0, 5, "AGAPE", "") && (m_length == 5)) ||
      ((m_current == 5) && StringAt(w, 0, 6, "RESUME", ""))) {
    MetaphAddAlt(ctx, "", "A");
    return;
  }

  // special case "inge" => 'INGA', 'INJ'
  if (StringAt(w, 0, 4, "INGE", "") && (m_length == 4)) {
    MetaphAddAlt(ctx, "A", "");
    return;
  }

  // special cases with two pronunciations
  // special handling due to the difference in
  // the pronunciation of the '-D'
  if ((m_current == 5) && StringAt(w, 0, 7, "BLESSED", "LEARNED", "")) {
    MetaphAddExactApprox(ctx, "D", "AD", "T", "AT");
    ctx->m_current += 2;
    return;
  }

  // encode all vowels and diphthongs to the same value
  if ((!E_Silent(ctx) && !ctx->flag_AL_inversion && !Silent_Internal_E(ctx)) ||
      E_Pronounced_Exceptions(ctx)) {
    MetaphAdd(ctx, "A");
  }

  // now that we've visited the vowel in question
  ctx->flag_AL_inversion = false;
}