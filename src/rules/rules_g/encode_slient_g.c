#include "rules/rules_g/encode_slient_g.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_Silent_G(Metaphone3 *ctx)
{

    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;
    int m_length = ctx->m_length;

    // e.g. "phlegm", "apothegm", "voigt"
    if ((((m_current + 1) == m_last) && (StringAt(w, (m_current - 1), 3, "EGM", "IGM", "AGM", "") || StringAt(w, m_current, 2, "GT", ""))) || (StringAt(w, 0, 5, "HUGES", "") && (m_length == 5)))
    {
        ctx->m_current++;
        return true;
    }

    // vietnamese names e.g. "Nguyen" but not "Ng"
    if (StringAt(w, 0, 2, "NG", "") && (m_current != m_last))
    {
        ctx->m_current++;
        return true;
    }

    return false;
}