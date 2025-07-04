#include "rules/rules_e/skip_silent_ue.h"
#include "utils/char_utils.h"
#include "utils/skip_vowels.h"
#include "utils/string_utils.h"

bool Skip_Silent_UE(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_length = ctx->m_length;
  int m_last = ctx->m_last;
  // always silent except for cases listed below
  if ((StringAt(w, (m_current - 1), 3, "QUE", "GUE", "") &&
       !StringAt(w, 0, 8, "BARBEQUE", "PALENQUE", "APPLIQUE", "")
       // '-que' cases usually french but missing the acute accent
       && !StringAt(w, 0, 6, "RISQUE", "") &&
       !StringAt(w, (m_current - 3), 5, "ARGUE", "SEGUE", "") &&
       !StringAt(w, 0, 7, "PIROGUE", "ENRIQUE", "") &&
       !StringAt(w, 0, 10, "COMMUNIQUE", "")) &&
      (m_current > 1) &&
      (((m_current + 1) == m_last) || StringAt(w, 0, 7, "JACQUES", "")))
  {
    int new_pos = SkipVowels(ctx, ctx->m_current);
    if (new_pos == ctx->m_current)
    {
      ctx->m_current++;
    }
    else
    {
      ctx->m_current = new_pos;
    }
    return true;
  }

  return false;
}