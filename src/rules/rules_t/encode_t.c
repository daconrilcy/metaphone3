#include "rules/rules_t/encode_t.h"
#include "rules/rules_t/encode_silent_french_t.h"
#include "rules/rules_t/encode_t_initial.h"
#include "rules/rules_t/encode_tch.h"
#include "rules/rules_t/encode_th.h"
#include "rules/rules_t/encode_th_pronounced_separately.h"
#include "rules/rules_t/encode_ti.h"
#include "rules/rules_t/encode_tient.h"
#include "rules/rules_t/encode_tsch.h"
#include "rules/rules_t/encode_tth.h"
#include "rules/rules_t/encode_tue_teu_teou_tul_tie.h"
#include "rules/rules_t/encode_tun_tul_tua_tuo.h"
#include "rules/rules_t/encode_tur_tiu_suffixes.h"
#include "rules/rules_t/encode_tzsch.h"

#include "utils/metaph_add.h"
#include "utils/string_utils.h"

void Encode_T(Metaphone3 *ctx)
{
  if (Encode_T_Initial(ctx) || Encode_TCH(ctx) || Encode_Silent_French_T(ctx) ||
      Encode_TUN_TUL_TUA_TUO(ctx) || Encode_TUE_TEU_TEOU_TUL_TIE(ctx) ||
      Encode_TUR_TIU_Suffixes(ctx) || Encode_TI(ctx) || Encode_TIENT(ctx) ||
      Encode_TSCH(ctx) || Encode_TZSCH(ctx) ||
      Encode_TH_Pronounced_Separately(ctx) || Encode_TTH(ctx) ||
      Encode_TH(ctx))
  {
    return;
  }

  // eat redundant 'T' or 'D'
  if (StringAt(ctx->m_inWord, (ctx->m_current + 1), 1, "T", "D", ""))
  {
    ctx->m_current += 2;
  }
  else
  {
    ctx->m_current++;
  }

  MetaphAdd(ctx, "T");
}