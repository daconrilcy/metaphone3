#include "rules/rules_m/encode_mpt.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_MPT(Metaphone3 *ctx)
{
    if (StringAt(ctx->m_inWord, (ctx->m_current - 2), 8, "COMPTROL", "") ||
        StringAt(ctx->m_inWord, (ctx->m_current - 4), 7, "ACCOMPT", ""))

    {
        MetaphAdd(ctx, "N");
        ctx->m_current += 2;
        return true;
    }

    return false;
}