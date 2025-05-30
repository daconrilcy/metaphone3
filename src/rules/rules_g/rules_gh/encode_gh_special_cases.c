#include "rules/rules_g/rules_gh/encode_gh_special_cases.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_GH_Special_Cases(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    bool handled = false;

    // special case: 'hiccough' == 'hiccup'
    if (StringAt(w, (m_current - 6), 8, "HICCOUGH", ""))
    {
        MetaphAdd(ctx, "P");
        handled = true;
    }
    // special case: 'lough' alt spelling for scots 'loch'
    else if (StringAt(w, 0, 5, "LOUGH", ""))
    {
        MetaphAdd(ctx, "K");
        handled = true;
    }
    // hungarian
    else if (StringAt(w, 0, 6, "BALOGH", ""))
    {
        MetaphAddExactApprox(ctx, "G", "", "K", "");
        handled = true;
    }
    // "maclaughlin"
    else if (StringAt(w, (m_current - 3), 8, "LAUGHLIN", "COUGHLAN", "LOUGHLIN", ""))
    {
        MetaphAddAlt(ctx, "K", "F");
        handled = true;
    }
    else if (StringAt(w, (m_current - 3), 5, "GOUGH", "") || StringAt(w, (m_current - 7), 9, "COLCLOUGH", ""))
    {
        MetaphAddAlt(ctx, "", "F");
        handled = true;
    }

    if (handled)
    {
        ctx->m_current += 2;
        return true;
    }

    return false;
}