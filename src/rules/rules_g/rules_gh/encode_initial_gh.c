#include "rules/rules_g/rules_gh/encode_initial_gh.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_Initial_GH(Metaphone3 *ctx)
{
    if (ctx->m_current < 3)
    {
        // e.g. "ghislane", "ghiradelli"
        if (ctx->m_current == 0)
        {
            if (CharAt(ctx->m_inWord, (ctx->m_current + 2)) == 'I')
            {
                MetaphAdd(ctx, "J");
            }
            else
            {
                MetaphAddExactApproxSimple(ctx, "G", "K");
            }
            ctx->m_current += 2;
            return true;
        }
    }

    return false;
}