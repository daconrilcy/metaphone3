#include "rules/rules_m/rules_mb/test_pronounced_mb_2.h"
#include "utils/string_utils.h"

bool Test_Pronounced_MB_2(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    // e.g. "bombastic", "umbrage", "flamboyant"
    if (StringAt(w, (m_current - 1), 5, "OMBAS", "OMBAD", "UMBRA", "") ||
        StringAt(w, (m_current - 3), 4, "FLAM", ""))
    {
        return true;
    }

    return false;
}