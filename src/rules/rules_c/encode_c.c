#include "rules/rules_c/encode_c.h"
#include "rules/rules_c/encode_silent_c_at_beginning.h"
#include "rules/rules_c/encode_ca_to_s.h"
#include "rules/rules_c/encode_co_to_s.h"
#include "rules/rules_c/rules_ch/encode_ch.h"
#include "rules/rules_c/encode_ccia.h"
#include "rules/rules_c/encode_cc.h"
#include "rules/rules_c/encode_ck_cg_cq.h"
#include "rules/rules_c/rules_front_vowel/encode_c_front_vowel.h"
#include "rules/rules_c/encode_silent_c.h"
#include "rules/rules_c/encode_cz.h"
#include "rules/rules_c/encode_cs.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

void Encode_C(Metaphone3 *ctx)
{
    int cur = ctx->m_current;

    // Appelle chaque sous-règle : si l'une retourne true, on sort directement
    if (
        Encode_Silent_C_At_Beginning(ctx) ||
        Encode_CA_To_S(ctx) ||
        Encode_CO_To_S(ctx) ||
        Encode_CH(ctx) ||
        Encode_CCIA(ctx) ||
        Encode_CC(ctx) ||
        Encode_CK_CG_CQ(ctx) ||
        Encode_C_Front_Vowel(ctx) ||
        Encode_Silent_C(ctx) ||
        Encode_CZ(ctx) ||
        Encode_CS(ctx))
    {
        return;
    }

    // Par défaut, si ce n'est pas doublé par une autre consonne
    if (!(cur >= 1 ? StringAt(ctx->m_inWord, cur - 1, 1, "C", "K", "G", "Q", "") : false))
    {
        MetaphAdd(ctx, "K");
    }

    // Cas des noms "mac caffrey", "mac gregor"
    if (StringAt(ctx->m_inWord, cur + 1, 2, " C", " Q", " G", ""))
    {
        ctx->m_current += 2;
    }
    else
    {
        if (StringAt(ctx->m_inWord, cur + 1, 1, "C", "K", "Q", "") && !StringAt(ctx->m_inWord, cur + 1, 2, "CE", "CI", ""))
        {
            ctx->m_current += 2;
            // Account for Ro-ckc-liffe, etc.
            if (StringAt(ctx->m_inWord, ctx->m_current, 1, "C", "K", "Q", "") && !StringAt(ctx->m_inWord, ctx->m_current + 1, 2, "CE", "CI", ""))
            {
                ctx->m_current++;
            }
        }
        else
        {
            ctx->m_current++;
        }
    }
}
