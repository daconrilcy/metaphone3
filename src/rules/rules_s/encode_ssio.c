#include "rules/rules_s/encode_ssio.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"
#include "utils/advance_counter.h"

bool Encode_SSIO(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    if (StringAt(w, (m_current + 1), 4, "SION", ""))
    {
        //"abcission"
        if (StringAt(w, (m_current - 2), 2, "CI", ""))
        {
            MetaphAdd(ctx, "J");
        }
        //'mission'
        else
        {
            if (IsVowel(CharAt(ctx->m_inWord, (ctx->m_current - 1))))
            {
                MetaphAdd(ctx, "X");
            }
        }

        AdvanceCounter(ctx, 4, 2);
        return true;
    }

    return false;
}