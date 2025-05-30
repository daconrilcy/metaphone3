#include "rules/rules_w/encode_witz_wicz.h"
#include "utils/advance_counter.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"
#include <string.h>

bool Encode_WITZ_WICZ(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  // polish e.g. 'filipowicz'
  if (((m_current + 3) == m_last) &&
      StringAt(w, m_current, 4, "WICZ", "WITZ", ""))
  {
    if (ctx->m_encodeVowels)
    {
      if ((ctx->m_primary->length > 0) &&
          (ctx->m_primary->data[ctx->m_primary->length - 1] == 'A'))
      {
        MetaphAddAlt(ctx, "TS", "FAX");
      }
      else
      {
        MetaphAddAlt(ctx, "ATS", "FAX");
      }
    }
    else
    {
      MetaphAddAlt(ctx, "TS", "FX");
    }
    ctx->m_current += 4;
    return true;
  }

  return false;
}