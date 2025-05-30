#include "rules/rules_l/encode_french_euil.h"
#include "utils/string_utils.h"

bool Encode_French_EUIL(Metaphone3 *ctx)
{
    // e.g. "auteuil"
    if (StringAt(ctx->m_inWord, (ctx->m_current - 3), 4, "EUIL", "") && (ctx->m_current == ctx->m_last))
    {
        ctx->m_current++;
        return true;
    }

    return false;
}