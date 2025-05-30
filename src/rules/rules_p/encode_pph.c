#include "rules/rules_p/encode_pph.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_PPH(Metaphone3 *ctx)
{
    // 'sappho'
    if ((CharAt(ctx->m_inWord, (ctx->m_current + 1)) == 'P') &&
        ((ctx->m_current + 2) < ctx->m_length) &&
        (CharAt(ctx->m_inWord, (ctx->m_current + 2)) == 'H'))
    {
        MetaphAdd(ctx, "F");
        ctx->m_current += 3;
        return true;
    }

    return false;
}