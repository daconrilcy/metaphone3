#include "rules/rules_z/encode_french_ez.h"
#include "utils/string_utils.h"

bool Encode_French_EZ(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    if (((m_current == 3) &&
         StringAt(w, (m_current - 3), 4, "CHEZ", "")) ||
        StringAt(w, (m_current - 5), 6, "RENDEZ", ""))
    {
        ctx->m_current++;
        return true;
    }

    return false;
}