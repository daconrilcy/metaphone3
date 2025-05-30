#include "rules/rules_g/rules_internal_hard_g/encode_hard_gen_gin_get_git.h"
#include "utils/string_utils.h"

bool Internal_Hard_GEN_GIN_GET_GIT(Metaphone3 *ctx)
{
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;
    int m_length = ctx->m_length;
    const char *w = ctx->m_inWord;

    if ((StringAt(w, (m_current - 3), 6, "FORGET", "TARGET", "MARGIT", "MARGET", "TURGEN", "BERGEN", "MORGEN", "JORGEN", "HAUGEN", "JERGEN",
                  "JURGEN", "LINGEN", "BORGEN", "LANGEN", "KLAGEN", "STIGER", "BERGER", "") &&
         !StringAt(w, m_current, 7, "GENETIC", "GENESIS", "") && !StringAt(w, (m_current - 4), 8, "PLANGENT", "")) ||
        (StringAt(w, (m_current - 3), 6, "BERGIN", "FEAGIN", "DURGIN", "") && ((m_current + 2) == m_last)) ||
        (StringAt(w, (m_current - 2), 5, "ENGEN", "") && !StringAt(w, (m_current + 3), 3, "DER", "ETI", "ESI", "")) ||
        StringAt(w, (m_current - 4), 7, "JUERGEN", "") ||
        StringAt(w, 0, 5, "NAGIN", "MAGIN", "HAGIN", "") ||
        (StringAt(w, 0, 5, "ENGIN", "DEGEN", "LAGEN", "MAGEN", "NAGIN", "") && (m_length == 5)) ||
        (StringAt(w, (m_current - 2), 5, "BEGET", "BEGIN", "HAGEN", "FAGIN", "BOGEN", "WIGIN", "NTGEN", "EIGEN", "WEGEN", "WAGEN", "") && !StringAt(w, (m_current - 5), 8, "OSPHAGEN", "")))
    {
        return true;
    }

    return false;
}