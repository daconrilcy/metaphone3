#include "rules/rules_x/encode_greek_x.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_Greek_X(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    // 'xylophone', xylem', 'xanthoma', 'xeno-'
    if (StringAt(w, (m_current + 1), 3, "YLO", "YLE", "ENO", "") ||
        StringAt(w, (m_current + 1), 4, "ANTH", ""))
    {
        MetaphAdd(ctx, "S");
        ctx->m_current++;
        return true;
    }

    return false;
}