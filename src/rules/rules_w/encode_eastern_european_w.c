#include "rules/rules_w/encode_eastern_european_w.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_Eastern_European_W(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;

    // Arnow should match Arnoff
    if (((m_current == m_last) && IsVowel(CharAt(w, (m_current - 1)))) ||
        StringAt(w, (m_current - 1), 5, "EWSKI", "EWSKY", "OWSKI", "OWSKY", "") ||
        (StringAt(w, m_current, 5, "WICKI", "WACKI", "") && ((m_current + 4) == m_last)) ||
        StringAt(w, m_current, 4, "WIAK", "") && ((m_current + 3) == m_last) ||
        StringAt(w, 0, 3, "SCH", ""))
    {
        MetaphAddExactApprox(ctx, "", "V", "", "F");
        ctx->m_current++;
        return true;
    }

    return false;
}