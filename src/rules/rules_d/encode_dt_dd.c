#include "rules/rules_d/encode_dt_dd.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_DT_DD(Metaphone3 *ctx)
{
  int cur = ctx->m_current;
  const char *w = ctx->m_inWord;

  // eat redundant 'T' or 'D'
  if (StringAt(w, cur, 2, "DT", "DD", ""))
  {
    if (StringAt(w, cur, 3, "DTH", ""))
    {
      MetaphAddExactApproxSimple(ctx, "D0", "T0");
      ctx->m_current += 3;
    }
    else
    {
      if (ctx->m_encodeExact)
      {
        // devoice it
        if (StringAt(w, cur, 2, "DT", ""))
        {
          MetaphAdd(ctx, "T");
        }
        else
        {
          MetaphAdd(ctx, "D");
        }
      }
      else
      {
        MetaphAdd(ctx, "T");
      }
      ctx->m_current += 2;
    }
    return true;
  }

  return false;
}