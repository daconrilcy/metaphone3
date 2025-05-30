#include "rules/rules_d/encode_d.h"
#include "rules/rules_d/encode_dg.h"
#include "rules/rules_d/encode_dj.h"
#include "rules/rules_d/encode_dt_dd.h"
#include "rules/rules_d/encode_d_to_j.h"
#include "rules/rules_d/encode_dous.h"
#include "rules/rules_d/encode_silent_d.h"

#include "metaphone3.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

void Encode_D(Metaphone3 *ctx)
{
  if (Encode_DG(ctx) ||
      Encode_DJ(ctx) ||
      Encode_DT_DD(ctx) ||
      Encode_D_To_J(ctx) ||
      Encode_DOUS(ctx) ||
      Encode_Silent_D(ctx))
  {
    return;
  }

  if (ctx->m_encodeExact)
  {
    // "final de-voicing" in this case
    // e.g. 'missed' == 'mist'
    if ((ctx->m_current == ctx->m_last) &&
        StringAt(ctx->m_inWord, (ctx->m_current - 3), 4, "SSED", ""))
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
  ctx->m_current++;
}