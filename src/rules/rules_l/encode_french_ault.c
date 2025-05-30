#include "rules/rules_l/encode_french_ault.h"
#include "utils/string_utils.h"
#include "utils/root_or_inflections.h"

bool Encode_French_AULT(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    // e.g. "renault" and "foucault", well known to americans, but not "fault"
    if ((m_current > 3) &&
        (StringAt(w, (m_current - 3), 5, "RAULT", "NAULT", "BAULT", "SAULT", "GAULT", "CAULT", "") ||
         StringAt(w, (m_current - 4), 6, "REAULT", "RIAULT", "NEAULT", "BEAULT", "")) &&
        !(RootOrInflections(w, "ASSAULT") ||
          StringAt(w, (m_current - 8), 10, "SOMERSAULT", "") ||
          StringAt(w, (m_current - 9), 11, "SUMMERSAULT", "")))
    {
        ctx->m_current += 2;
        return true;
    }

    return false;
}