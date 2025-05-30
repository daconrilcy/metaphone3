#include "rules/rules_x/encode_french_x_final.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_French_X_Final(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;

    // french e.g. "breaux", "paix"
    if (!((m_current == m_last) &&
          (StringAt(w, (m_current - 3), 3, "IAU", "EAU", "IEU", "") ||
           StringAt(w, (m_current - 2), 2, "AI", "AU", "OU", "OI", "EU", ""))))
    {
        MetaphAdd(ctx, "KS");
    }

    return false;
}