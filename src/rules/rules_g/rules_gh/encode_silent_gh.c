#include "rules/rules_g/rules_gh/encode_silent_gh.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"

bool Encode_Silent_GH(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;

    // Parker's rule (with some further refinements) - e.g., 'hugh'
    if (((((m_current > 1) && StringAt(w, (m_current - 2), 1, "B", "H", "D", "G", "L", ""))
          // e.g., 'bough'
          || ((m_current > 2) && StringAt(w, (m_current - 3), 1, "B", "H", "D", "K", "W", "N", "P", "V", "") && !StringAt(w, 0, 6, "ENOUGH", ""))
          // e.g., 'broughton'
          || ((m_current > 3) && StringAt(w, (m_current - 4), 1, "B", "H", ""))
          //'plough', 'slaugh'
          || ((m_current > 3) && StringAt(w, (m_current - 4), 2, "PL", "SL", "")) ||
          ((m_current > 0)
           // 'sigh', 'light'
           && ((CharAt(w, (m_current - 1)) == 'I') || StringAt(w, 0, 4, "PUGH", "")
               // e.g. 'MCDONAGH', 'MURTAGH', 'CREAGH'
               || (StringAt(w, (m_current - 1), 3, "AGH", "") && ((m_current + 1) == m_last)) || StringAt(w, (m_current - 4), 6, "GERAGH", "DRAUGH", "") || (StringAt(w, (m_current - 3), 5, "GAUGH", "GEOGH", "MAUGH", "") && !StringAt(w, 0, 9, "MCGAUGHEY", ""))
               // exceptions to 'tough', 'rough', 'lough'
               || (StringAt((m_current - 2), 4, "OUGH", "") && (m_current > 3) && !StringAt(w, (m_current - 4), 6, "CCOUGH", "ENOUGH", "TROUGH", "CLOUGH", "")))))
         // suffixes starting w/ vowel where "-GH-" is usually silent
         && (StringAt(w, (m_current - 3), 5, "VAUGH", "FEIGH", "LEIGH", "") ||
             StringAt(w, (m_current - 2), 4, "HIGH", "TIGH", "") ||
             ((m_current + 1) == m_last) ||
             (StringAt(w, (m_current + 2), 2, "IE", "EY", "ES", "ER", "ED", "TY", "") &&
              ((m_current + 3) == m_last) && !StringAt(w, (m_current - 5), 9, "GALLAGHER", "")) ||
             (StringAt(w, (m_current + 2), 1, "Y", "") && ((m_current + 2) == m_last)) ||
             (StringAt(w, (m_current + 2), 3, "ING", "OUT", "") && ((m_current + 4) == m_last)) ||
             (StringAt(w, (m_current + 2), 4, "ERTY", "") && ((m_current + 5) == m_last)) ||
             (!IsVowel(CharAt(w, (m_current + 2))) || StringAt(w, (m_current - 3), 5, "GAUGH", "GEOGH", "MAUGH", "") || StringAt(w, (m_current - 4), 8, "BROUGHAM", ""))))
        // exceptions where '-g-' pronounced
        && !(StringAt(w, 0, 6, "BALOGH", "SABAGH", "") ||
             StringAt(w, (m_current - 2), 7, "BAGHDAD", "") ||
             StringAt(w, (m_current - 3), 5, "WHIGH", "") ||
             StringAt(w, (m_current - 5), 7, "SABBAGH", "AKHLAGH", "")))
    {
        // silent - do nothing
        ctx->m_current += 2;
        return true;
    }

    return false;
}