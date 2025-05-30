#include "rules/rules_v.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

void Encode_V(Metaphone3 *ctx)
{
    // eat redundant 'V'
    if (CharAt(ctx->m_inWord, (ctx->m_current + 1)) == 'V')
    {
        ctx->m_current += 2;
    }
    else
    {
        ctx->m_current++;
    }

    MetaphAddExactApproxSimple(ctx, "V", "F");
}
