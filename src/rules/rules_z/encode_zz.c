#include "rules/rules_z/encode_zz.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_ZZ(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;

    // "abruzzi", 'pizza'
    if ((CharAt(w, (m_current + 1)) == 'Z') &&
        ((StringAt(w, (m_current + 2), 1, "I", "O", "A", "") &&
          ((m_current + 2) == m_last)) ||
         StringAt(w, (m_current - 2), 9, "MOZZARELL", "PIZZICATO", "PUZZONLAN", "")))
    {
        MetaphAddAlt(ctx, "TS", "S");
        ctx->m_current += 2;
        return true;
    }

    return false;
}