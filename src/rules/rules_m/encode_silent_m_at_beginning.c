#include "rules/rules_m/encode_silent_m_at_beginning.h"
#include "utils/string_utils.h"

bool Encode_Silent_M_At_Beginning(Metaphone3 *ctx)
{
    // skip these when at start of word
    if ((ctx->m_current == 0) && StringAt(ctx->m_inWord, ctx->m_current, 2, "MN", ""))
    {
        ctx->m_current += 1;
        return true;
    }

    return false;
}