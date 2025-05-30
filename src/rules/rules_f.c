#include "rules/rules_f.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

void Encode_F(Metaphone3 *ctx)
{
    // Encode cases where "-FT-" => "T" is usually silent
    // e.g. 'often', 'soften'
    // This should really be covered under "T"!
    if (StringAt(ctx->m_inWord, (ctx->m_current - 1), 5, "OFTEN", ""))
    {
        MetaphAddAlt(ctx, "F", "FT");
        ctx->m_current += 2;
        return;
    }

    // eat redundant 'F'
    if (CharAt(ctx->m_inWord, (ctx->m_current + 1)) == 'F')
    {
        ctx->m_current += 2;
    }
    else
    {
        ctx->m_current++;
    }

    MetaphAdd(ctx, "F");
}