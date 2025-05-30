#include "rules/rules_s/encode_isten.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"
#include "utils/root_or_inflections.h"

bool Encode_ISTEN(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    // 't' is silent in verb, pronounced in name
    if (StringAt(w, 0, 8, "CHRISTEN", ""))
    {
        // the word itself
        if (RootOrInflections(w, "CHRISTEN") || StringAt(w, 0, 11, "CHRISTENDOM", ""))
        {
            MetaphAddAlt(ctx, "S", "ST");
        }
        else
        {
            // e.g. 'christenson', 'christene'
            MetaphAdd(ctx, "ST");
        }
        ctx->m_current += 2;
        return true;
    }

    // e.g. 'glisten', 'listen'
    if (StringAt(w, (m_current - 2), 6, "LISTEN", "RISTEN", "HASTEN", "FASTEN", "MUSTNT", "") ||
        StringAt(w, (m_current - 3), 7, "MOISTEN", ""))
    {
        MetaphAdd(ctx, "S");
        ctx->m_current += 2;
        return true;
    }

    return false;
}