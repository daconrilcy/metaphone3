#include "utils/slavo_germanic.h"
#include "utils/string_utils.h"
#include "utils/char_utils.h"

// Attention : fonctionne sur le mot complet stocké dans ctx->m_inWord
bool SlavoGermanic(Metaphone3 *ctx)
{
    if (!ctx || !ctx->m_inWord)
        return false;
    const char *w = ctx->m_inWord;

    if (StringAt(w, 0, 3, "SCH", "") ||
        StringAt(w, 0, 2, "SW", "") ||
        CharAt(w, 0) == 'J' ||
        CharAt(w, 0) == 'W')
    {
        return true;
    }
    return false;
}