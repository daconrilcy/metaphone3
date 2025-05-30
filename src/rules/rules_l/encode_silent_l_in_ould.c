#include "rules/rules_l/encode_silent_l_in_ould.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_Silent_L_In_OULD(Metaphone3 *ctx)
{

    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    //'would', 'could'
    if (StringAt(w, (m_current - 3), 5, "WOULD", "COULD", "") ||
        (StringAt(w, (m_current - 4), 6, "SHOULD", "") &&
         !StringAt(w, (m_current - 4), 8, "SHOULDER", "")))
    {
        MetaphAddExactApproxSimple(ctx, "D", "T");
        ctx->m_current += 2;
        return true;
    }

    return false;
}