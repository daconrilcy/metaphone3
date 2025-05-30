#include "rules/rules_m/rules_mb/test_silent_mb_2.h"
#include "utils/string_utils.h"

bool Test_Silent_MB_2(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;

    // 'M' is the current letter
    if ((CharAt(w, (m_current + 1)) == 'B') &&
        (m_current > 1) &&
        (((m_current + 1) == m_last)
         // other situations where "-MB-" is at end of root
         // but not at end of word. The tests are for standard
         // noun suffixes.
         // e.g. "climbing" => KLMNK
         || StringAt(w, (m_current + 2), 3, "ING", "ABL", "") ||
         StringAt(w, (m_current + 2), 4, "LIKE", "") ||
         ((CharAt(w, (m_current + 2)) == 'S') && ((m_current + 2) == m_last)) ||
         StringAt(w, (m_current - 5), 7, "BUNCOMB", "")
         // e.g. "bomber",
         || (StringAt(w, (m_current + 2), 2, "ED", "ER", "") &&
             ((m_current + 3) == m_last) &&
             (StringAt(w, 0, 5, "CLIMB", "PLUMB", "")
              // e.g. "beachcomber"
              || !StringAt(w, (m_current - 1), 5, "IMBER", "AMBER", "EMBER", "UMBER", ""))
             // exceptions
             && !StringAt(w, (m_current - 2), 6, "CUMBER", "SOMBER", ""))))
    {
        return true;
    }

    return false;
}