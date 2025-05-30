#include "rules/rules_s/encode_sea_sui_sier.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"
#include "utils/advance_counter.h"

bool Encode_SEA_SUI_SIER(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;

    // "nausea" by itself has => NJ as a more likely encoding. Other forms
    // using "nause-" (see Encode_SEA()) have X or S as more familiar pronounciations
    if ((StringAt(w, (m_current - 3), 6, "NAUSEA", "") && ((m_current + 2) == m_last))
        // e.g. "casuistry", "frasier", "hoosier"
        || StringAt(w, (m_current - 2), 5, "CASUI", "") ||
        (StringAt(w, (m_current - 1), 5, "OSIER", "ASIER", "") &&
         !(StringAt(w, 0, 6, "EASIER", "") ||
           StringAt(w, 0, 5, "OSIER", "") ||
           StringAt(w, (m_current - 2), 6, "ROSIER", "MOSIER", ""))))
    {
        MetaphAddAlt(ctx, "J", "X");
        AdvanceCounter(ctx, 3, 1);
        return true;
    }

    return false;
}