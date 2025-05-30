#include "rules/rules_e/e_silent_suffix.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"

bool E_Silent_Suffix(Metaphone3 *ctx, int at)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_length = ctx->m_length;
    int m_last = ctx->m_last;

    if ((m_current == (at - 1)) && (m_length > (at + 1)) &&
        (IsVowel(CharAt(w, (at + 1))) ||
         (StringAt(w, at, 2, "ST", "SL", "") && (m_length > (at + 2)))))
    {
        return true;
    }

    return false;
}