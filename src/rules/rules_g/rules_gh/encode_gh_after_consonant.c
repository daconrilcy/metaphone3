#include "rules/rules_g/rules_gh/encode_gh_after_consonant.h"
#include "utils/string_utils.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"

bool Encode_GH_After_Consonant(Metaphone3 *ctx)
{
    // e.g. 'burgher', 'bingham'
    if ((ctx->m_current > 0) && !IsVowel(CharAt(ctx->m_inWord, (ctx->m_current - 1)))
        // not e.g. 'greenhalgh'
        && !(StringAt(ctx->m_inWord, (ctx->m_current - 3), 5, "HALGH", "") && ((ctx->m_current + 1) == ctx->m_last)))
    {
        MetaphAddExactApproxSimple(ctx, "G", "K");
        ctx->m_current += 2;
        return true;
    }

    return false;
}