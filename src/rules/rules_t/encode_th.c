#include "rules/rules_t/encode_th.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_TH(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_length = ctx->m_length;

    if (StringAt(w, m_current, 2, "TH", ""))
    {
        //'-clothes-'
        if (StringAt(w, (m_current - 3), 7, "CLOTHES", ""))
        {
            // vowel already encoded so skip right to S
            ctx->m_current += 3;
            return true;
        }

        // special case "thomas", "thames", "beethoven" or germanic words
        if (StringAt(w, (m_current + 2), 4, "OMAS", "OMPS", "OMPK", "OMSO", "OMSE",
                     "AMES", "OVEN", "OFEN", "ILDA", "ILDE", "") ||
            (StringAt(w, 0, 4, "THOM", "") && (m_length == 4)) ||
            (StringAt(w, 0, 5, "THOMS", "") && (m_length == 5)) ||
            StringAt(w, 0, 4, "VAN ", "VON ", "") ||
            StringAt(w, 0, 3, "SCH", ""))
        {
            MetaphAdd(ctx, "T");
        }
        else
        {
            // give an 'etymological' 2nd
            // encoding for "smith"
            if (StringAt(w, 0, 2, "SM", ""))
            {
                MetaphAddAlt(ctx, "0", "T");
            }
            else
            {
                MetaphAdd(ctx, "0");
            }
        }

        ctx->m_current += 2;
        return true;
    }

    return false;
}