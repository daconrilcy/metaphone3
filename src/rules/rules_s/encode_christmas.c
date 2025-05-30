#include "rules/rules_s/encode_christmas.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_Christmas(Metaphone3 *ctx)
{
    //'christmas'
    if (StringAt(ctx->m_inWord, (ctx->m_current - 4), 8, "CHRISTMA", ""))
    {
        MetaphAdd(ctx, "SM");
        ctx->m_current += 3;
        return true;
    }

    return false;
}