#include "rules/rules_g/rules_gh/encode_ught.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_UGHT(Metaphone3 *ctx)
{
    int m_current = ctx->m_current;
    const char *w = ctx->m_inWord;

    // e.g. "ought", "aught", "daughter", "slaughter"
    if (StringAt(w, (m_current - 1), 4, "UGHT", ""))
    {
        if ((StringAt(w, (m_current - 3), 5, "LAUGH", "") &&
             !(StringAt(w, (m_current - 4), 7, "SLAUGHT", "") ||
               StringAt(w, (m_current - 3), 7, "LAUGHTO", ""))) ||
            StringAt(w, (m_current - 4), 6, "DRAUGH", ""))
        {
            MetaphAdd(ctx, "FT");
        }
        else
        {
            MetaphAdd(ctx, "T");
        }
        ctx->m_current += 3;
        return true;
    }

    return false;
}