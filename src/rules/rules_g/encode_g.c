#include "rules/rules_g/encode_g.h"
#include "rules/rules_g/encode_silent_g_at_beginning.h"
#include "rules/rules_g/encode_gg.h"
#include "rules/rules_g/encode_gk.h"
#include "rules/rules_g/rules_gh/encode_gh.h"
#include "rules/rules_g/encode_slient_g.h"
#include "rules/rules_g/encode_gn.h"
#include "rules/rules_g/encode_gl.h"
#include "rules/rules_g/encode_initial_g_front_vowel.h"
#include "rules/rules_g/encode_nger.h"
#include "rules/rules_g/encode_ger.h"
#include "rules/rules_g/encode_gel.h"
#include "rules/rules_g/encode_non_initial_g_front_vowel.h"
#include "rules/rules_g/encode_ga_to_j.h"

#include "utils/metaph_add.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

void Encode_G(Metaphone3 *ctx)
{
    if (
        Encode_Silent_G_At_Beginning(ctx) ||
        Encode_GG(ctx) ||
        Encode_GK(ctx) ||
        Encode_GH(ctx) ||
        Encode_Silent_G(ctx) ||
        Encode_GN(ctx) ||
        Encode_GL(ctx) ||
        Encode_Initial_G_Front_Vowel(ctx) ||
        Encode_NGER(ctx) ||
        Encode_GER(ctx) ||
        Encode_GEL(ctx) ||
        Encode_Non_Initial_G_Front_Vowel(ctx) ||
        Encode_GA_To_J(ctx))
    {
        return;
    }

    if (!StringAt(ctx->m_inWord, (ctx->m_current - 1), 1, "C", "K", "G", "Q", ""))
    {
        MetaphAddExactApproxSimple(ctx, "G", "K");
    }

    ctx->m_current++;
}