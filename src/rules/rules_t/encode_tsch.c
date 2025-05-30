#include "rules/rules_t/encode_tsch.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_TSCH(Metaphone3 *ctx)
{
    //'deutsch'
    if (StringAt(ctx->m_inWord, ctx->m_current, 4, "TSCH", "")
        // combining forms in german where the 'T' is pronounced seperately
        && !StringAt(ctx->m_inWord, (ctx->m_current - 3), 4, "WELT", "KLAT", "FEST", ""))
    {
        // pronounced the same as "ch" in "chit" => X
        MetaphAdd(ctx, "X");
        ctx->m_current += 4;
        return true;
    }

    return false;
}