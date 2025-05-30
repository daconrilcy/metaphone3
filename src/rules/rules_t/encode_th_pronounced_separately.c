#include "rules/rules_t/encode_th_pronounced_separately.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_TH_Pronounced_Separately(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;

    //'adulthood', 'bithead', 'apartheid'
    if (((m_current > 0) &&
         StringAt(w, (m_current + 1), 4, "HOOD", "HEAD", "HEID", "HAND", "HILL", "HOLD", "HAWK", "HEAP", "HERD", "HOLE", "HOOK", "HUNT", "HUMO", "HAUS", "HOFF", "HARD", "") &&
         !StringAt(w, (m_current - 3), 5, "SOUTH", "NORTH", "")) ||
        StringAt(w, (m_current + 1), 5, "HOUSE", "HEART", "HASTE", "HYPNO", "HEQUE", "")
        // watch out for greek root "-thallic"
        || (StringAt(w, (m_current + 1), 4, "HALL", "") && ((m_current + 4) == m_last) &&
            !StringAt(w, (m_current - 3), 5, "SOUTH", "NORTH", "")) ||
        (StringAt(w, (m_current + 1), 3, "HAM", "") &&
         ((m_current + 3) == m_last) &&
         !(StringAt(w, 0, 6, "GOTHAM", "WITHAM", "LATHAM", "") ||
           StringAt(w, 0, 7, "BENTHAM", "WALTHAM", "WORTHAM", "") ||
           StringAt(w, 0, 8, "GRANTHAM", ""))) ||
        (StringAt(w, (m_current + 1), 5, "HATCH", "") &&
         !((m_current == 0) || StringAt(w, (m_current - 2), 8, "UNTHATCH", ""))) ||
        StringAt(w, (m_current - 3), 7, "WARTHOG", "")
        // and some special cases where "-TH-" is usually pronounced 'T'
        || StringAt(w, (m_current - 2), 6, "ESTHER", "") ||
        StringAt(w, (m_current - 3), 6, "GOETHE", "") ||
        StringAt(w, (m_current - 2), 8, "NATHALIE", ""))
    {
        // special case
        if (StringAt(w, (m_current - 3), 7, "POSTHUM", ""))
        {
            MetaphAdd(ctx, "X");
        }
        else
        {
            MetaphAdd(ctx, "T");
        }
        ctx->m_current += 2;
        return true;
    }

    return false;
}