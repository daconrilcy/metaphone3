#include "rules/rules_e/e_silent.h"
#include "rules/rules_e/e_pronounced_at_end.h"
#include "utils/string_utils.h"

bool E_Silent(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_length = ctx->m_length;
    int m_last = ctx->m_last;

    if (E_Pronounced_At_End(ctx))
    {
        return false;
    }

    // 'e' silent when last letter, altho
    if ((m_current == m_last)
        // also silent if before plural 's'
        // or past tense or participle 'd', e.g.
        // 'grapes' and 'banished' => PNXT
        || ((StringAt(w, m_last, 1, "S", "D", "") && (m_current > 1) && ((m_current + 1) == m_last)
             // and not e.g. "nested", "rises", or "pieces" => RASAS
             && !(StringAt(w, (m_current - 1), 3, "TED", "SES", "CES", "") ||
                  StringAt(w, 0, 9, "ANTIPODES", "ANOPHELES", "") ||
                  StringAt(w, 0, 8, "MOHAMMED", "MUHAMMED", "MOUHAMED", "") ||
                  StringAt(w, 0, 7, "MOHAMED", "") ||
                  StringAt(w, 0, 6, "NORRED", "MEDVED", "MERCED", "ALLRED", "KHALED", "RASHED", "MASJED", "") ||
                  StringAt(w, 0, 5, "JARED", "AHMED", "HAMED", "JAVED", "") ||
                  StringAt(w, 0, 4, "ABED", "IMED", ""))))
        // e.g.  'wholeness', 'boneless', 'barely'
        || (StringAt(w, (m_current + 1), 4, "NESS", "LESS", "") &&
            ((m_current + 4) == m_last)) ||
        (StringAt(w, (m_current + 1), 2, "LY", "") &&
         ((m_current + 2) == m_last) &&
         !StringAt(w, 0, 6, "CICELY", "")))
    {
        return true;
    }

    return false;
}