#include "rules/rules_m/rules_mb/test_mn.h"
#include "utils/string_utils.h"

bool Test_MN(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;

    if ((CharAt(w, (m_current + 1)) == 'N') &&
        (((m_current + 1) == m_last)
         // or at the end of a word but followed by suffixes
         || (StringAt(w, (m_current + 2), 3, "ING", "EST", "") &&
             ((m_current + 4) == m_last)) ||
         ((CharAt(w, (m_current + 2)) == 'S') &&
          ((m_current + 2) == m_last)) ||
         (StringAt(w, (m_current + 2), 2, "LY", "ER", "ED", "") &&
          ((m_current + 3) == m_last)) ||
         StringAt(w, (m_current - 2), 9, "DAMNEDEST", "") ||
         StringAt(w, (m_current - 5), 9, "GODDAMNIT", "")))
    {
        return true;
    }

    return false;
}