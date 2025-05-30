#include "rules/rules_g/rules_internal_hard_g/encode_internal_hard_g_other.h"
#include "utils/string_utils.h"

bool Internal_Hard_G_Other(Metaphone3 *ctx)
{
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;
    int m_length = ctx->m_length;
    const char *w = ctx->m_inWord;

    if ((StringAt(w, m_current, 4, "GETH", "GEAR", "GEIS", "GIRL", "GIVI", "GIVE", "GIFT", "GIRD", "GIRT", "GILV", "GILD", "GELD", "") && !StringAt(w, (m_current - 3), 6, "GINGIV", "")) ||
        // "gish" but not "largish"
        (StringAt(w, (m_current + 1), 3, "ISH", "") && (m_current > 0) && !StringAt(w, 0, 4, "LARG", "")) ||
        (StringAt(w, (m_current - 2), 5, "MAGED", "MEGID", "") && !((m_current + 2) == m_last)) ||
        StringAt(w, m_current, 3, "GEZ", "") ||
        StringAt(w, 0, 4, "WEGE", "HAGE", "") ||
        (StringAt(w, (m_current - 2), 6, "ONGEST", "UNGEST", "") && ((m_current + 3) == m_last) && !StringAt(w, (m_current - 3), 7, "CONGEST", "")) ||
        StringAt(w, 0, 5, "VOEGE", "BERGE", "HELGE", "") ||
        (StringAt(w, 0, 4, "ENGE", "BOGY", "") && (m_length == 4)) ||
        StringAt(w, m_current, 6, "GIBBON", "") ||
        StringAt(w, 0, 10, "CORREGIDOR", "") ||
        StringAt(w, 0, 8, "INGEBORG", "") ||
        (StringAt(w, m_current, 4, "GILL", "") && (((m_current + 3) == m_last) || ((m_current + 4) == m_last)) && !StringAt(w, 0, 8, "STURGILL", "")))
    {
        return true;
    }

    return false;
}