#include "rules/rules_s/encode_s.h"
#include "rules/rules_s/encode_christmas.h"
#include "rules/rules_s/encode_isl.h"
#include "rules/rules_s/encode_isten.h"
#include "rules/rules_s/encode_sch.h"
#include "rules/rules_s/encode_sh.h"
#include "rules/rules_s/encode_sia.h"
#include "rules/rules_s/encode_silent_french_s_final.h"
#include "rules/rules_s/encode_silent_french_s_internal.h"
#include "rules/rules_s/encode_sio.h"
#include "rules/rules_s/encode_sj.h"
#include "rules/rules_s/encode_skj.h"
#include "rules/rules_s/encode_special_sw.h"
#include "rules/rules_s/encode_ss.h"
#include "rules/rules_s/encode_ssio.h"
#include "rules/rules_s/encode_sthm.h"
#include "rules/rules_s/encode_stl.h"
#include "rules/rules_s/encode_su.h"
#include "rules/rules_s/encode_sugar.h"
#include "rules/rules_s/encode_sur.h"
#include "rules/rules_s/encode_anglicisations.h"
#include "rules/rules_s/encode_sc.h"
#include "rules/rules_s/encode_sea_sui_sier.h"
#include "rules/rules_s/encode_sea.h"

#include "utils/string_utils.h"
#include "utils/metaph_add.h"

void Encode_S(Metaphone3 *ctx)
{
    if (Encode_SKJ(ctx) ||
        Encode_Special_SW(ctx) ||
        Encode_SJ(ctx) ||
        Encode_Silent_French_S_Final(ctx) ||
        Encode_Silent_French_S_Internal(ctx) ||
        Encode_ISL(ctx) ||
        Encode_STL(ctx) ||
        Encode_Christmas(ctx) ||
        Encode_STHM(ctx) ||
        Encode_ISTEN(ctx) ||
        Encode_Sugar(ctx) ||
        Encode_SH(ctx) ||
        Encode_SCH(ctx) ||
        Encode_SUR(ctx) ||
        Encode_SU(ctx) ||
        Encode_SSIO(ctx) ||
        Encode_SS(ctx) ||
        Encode_SIA(ctx) ||
        Encode_SIO(ctx) ||
        Encode_Anglicisations(ctx) ||
        Encode_SC(ctx) ||
        Encode_SEA_SUI_SIER(ctx) ||
        Encode_SEA(ctx))
    {
        return;
    }

    MetaphAdd(ctx, "S");

    if (StringAt(ctx->m_inWord, (ctx->m_current + 1), 1, "S", "Z", "") &&
        !StringAt(ctx->m_inWord, (ctx->m_current + 1), 2, "SH", ""))
    {
        ctx->m_current += 2;
    }
    else
    {
        ctx->m_current++;
    }
}