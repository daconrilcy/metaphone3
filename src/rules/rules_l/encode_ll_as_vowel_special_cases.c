#include "rules/rules_l/encode_ll_as_vowel_special_cases.h"
#include "utils/string_utils.h"

bool Encode_LL_As_Vowel_Special_Cases(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;
    int m_length = ctx->m_length;

    if (StringAt(w, (m_current - 5), 8, "TORTILLA", "") ||
        StringAt(w, (m_current - 8), 11, "RATATOUILLE", "")
        // e.g. 'guillermo', "veillard"
        || (StringAt(w, 0, 5, "GUILL", "VEILL", "GAILL", "")
            // 'guillotine' usually has '-ll-' pronounced as 'L' in english
            && !(StringAt(w, (m_current - 3), 7, "GUILLOT", "GUILLOR", "GUILLEN", "") ||
                 (StringAt(w, 0, 5, "GUILL", "") && (m_length == 5))))
        // e.g. "brouillard", "gremillion"
        || StringAt(w, 0, 7, "BROUILL", "GREMILL", "ROBILL", "")
        // e.g. 'mireille'
        || (StringAt(w, (m_current - 2), 5, "EILLE", "") && ((m_current + 2) == m_last)
            // exception "reveille" usually pronounced as 're-vil-lee'
            && !StringAt(w, (m_current - 5), 8, "REVEILLE", "")))
    {
        ctx->m_current += 2;
        return true;
    }

    return false;
}