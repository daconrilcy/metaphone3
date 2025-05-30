#include "rules/rules_s/encode_isl.h"
#include "utils/string_utils.h"

bool Encode_ISL(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    // special cases 'island', 'isle', 'carlisle', 'carlysle'
    if ((StringAt(w, (m_current - 2), 4, "LISL", "LYSL", "AISL", "") &&
         !StringAt(w, (m_current - 3), 7, "PAISLEY", "BAISLEY", "ALISLAM", "ALISLAH", "ALISLAA", "")) ||
        ((m_current == 1) && ((StringAt(w, (m_current - 1), 4, "ISLE", "") ||
                               StringAt(w, (m_current - 1), 5, "ISLAN", "")) &&
                              !StringAt(w, (m_current - 1), 5, "ISLEY", "ISLER", ""))))
    {
        ctx->m_current++;
        return true;
    }

    return false;
}