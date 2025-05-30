#include "rules/rules_l/interpolate_vowel_when_cons_l_at_end.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Interpolate_Vowel_When_Cons_L_At_End(Metaphone3 *ctx)
{
    if (ctx->m_encodeVowels == true)
    {
        // e.g. "ertl", "vogl"
        if ((ctx->m_current == ctx->m_last) && StringAt(ctx->m_inWord, (ctx->m_current - 1), 1, "D", "G", "T", ""))
        {
            MetaphAdd(ctx, "A");
        }
    }
}