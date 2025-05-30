#include "rules/rules_t/encode_tun_tul_tua_tuo.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_TUN_TUL_TUA_TUO(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    // e.g. "fortune", "fortunate"
    if (StringAt(w, (m_current - 3), 6, "FORTUN", "")
        // e.g. "capitulate"
        || (StringAt(w, m_current, 3, "TUL", "") &&
            (IsVowel(CharAt(ctx->m_inWord, (ctx->m_current - 1))) &&
             IsVowel(CharAt(ctx->m_inWord, (m_current + 3)))))
        // e.g. "obituary", "barbituate"
        || StringAt(w, (m_current - 2), 5, "BITUA", "BITUE", "")
        // e.g. "actual"
        || ((m_current > 1) && StringAt(w, m_current, 3, "TUA", "TUO", "")))
    {
        MetaphAddAlt(ctx, "X", "T");
        ctx->m_current++;
        return true;
    }

    return false;
}