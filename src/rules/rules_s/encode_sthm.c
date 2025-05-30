#include "rules/rules_s/encode_sthm.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_STHM(Metaphone3 *ctx)
{
    //'asthma', 'isthmus'
    if (StringAt(ctx->m_inWord, ctx->m_current, 4, "STHM", ""))
    {
        MetaphAdd(ctx, "SM");
        ctx->m_current += 4;
        return true;
    }

    return false;
}