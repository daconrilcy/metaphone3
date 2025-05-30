#include "rules/various/encode_vowels.h"
#include "rules/rules_e/encode_e_pronounced.h"
#include "rules/rules_e/skip_silent_ue.h"
#include "rules/various/o_silent.h"
#include "utils/metaph_add.h"
#include "utils/skip_vowels.h"
#include "utils/string_utils.h"
#include "utils/char_utils.h"

void Encode_Vowels(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  if (m_current == 0)
  {
    // all init vowels map to 'A'
    // as of Double Metaphone
    MetaphAdd(ctx, "A");
  }
  else if (ctx->m_encodeVowels)
  {
    if (CharAt(w, m_current) != 'E')
    {
      if (Skip_Silent_UE(ctx))
      {
        return;
      }

      if (O_Silent(ctx))
      {
        ctx->m_current++;
        return;
      }

      // encode all vowels and
      // diphthongs to the same value
      MetaphAdd(ctx, "A");
    }
    else
    {
      Encode_E_Pronounced(ctx);
    }
  }

  if (!(!IsVowel(CharAt(w, (m_current - 2))) &&
        StringAt(w, (m_current - 1), 4, "LEWA", "LEWO", "LEWI", "")))
  {
    ctx->m_current = SkipVowels(ctx, m_current);
  }
  else
  {
    ctx->m_current++;
  }
}