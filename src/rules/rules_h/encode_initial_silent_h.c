#include "rules/rules_h/encode_initial_silent_h.h"
#include "utils/metaph_add.h"
#include "utils/skip_vowels.h"
#include "utils/string_utils.h"

bool Encode_Initial_Silent_H(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;
  int m_length = ctx->m_length;

  //'hour', 'herb', 'heir', 'honor'
  if (StringAt(w, (m_current + 1), 3, "OUR", "ERB", "EIR", "") ||
      StringAt(w, (m_current + 1), 4, "ONOR", "") ||
      StringAt(w, (m_current + 1), 5, "ONOUR", "ONEST", ""))
  {
    // british pronounce H in this word
    // americans give it 'H' for the name,
    // no 'H' for the plant
    if ((m_current == 0) && StringAt(w, m_current, 4, "HERB", ""))
    {
      if (ctx->m_encodeVowels)
      {
        MetaphAddAlt(ctx, "HA", "A");
      }
      else
      {
        MetaphAddAlt(ctx, "H", "A");
      }
    }
    else if ((m_current == 0) || ctx->m_encodeVowels)
    {
      MetaphAdd(ctx, "A");
    }

    ctx->m_current++;
    // don't encode vowels twice
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