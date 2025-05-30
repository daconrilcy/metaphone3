#include "rules/rules_h/encode_h_pronounced.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"
#include "utils/advance_counter.h"

bool Encode_H_Pronounced(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    if ((((m_current == 0) || IsVowel(CharAt(w, (m_current - 1))) ||
          ((m_current > 0) && (CharAt(w, (m_current - 1)) == 'W'))) &&
         IsVowel(CharAt(w, (m_current + 1)))) ||
        // e.g. 'alWahhab'
        ((CharAt(w, (m_current + 1)) == 'H') && IsVowel(CharAt(w, (m_current + 2)))))
    {
        MetaphAdd(ctx, "H");
        AdvanceCounter(ctx, 2, 1);
        return true;
    }

    return false;
}