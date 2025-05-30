#include "rules/rules_j/rules_other_j/encode_j_to_j.h"
#include "rules/various/names_beginning_with_j_that_get_alt_y.h"

#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/skip_vowels.h"
#include "utils/string_utils.h"

bool Encode_J_To_J(Metaphone3 *ctx)
{
    if (IsVowel(CharAt(ctx->m_inWord, (ctx->m_current + 1))))
    {
        if ((ctx->m_current == 0) && Names_Beginning_With_J_That_Get_Alt_Y(ctx))
        {
            // 'Y' is a vowel so encode
            // is as 'A'
            if (ctx->m_encodeVowels)
            {
                MetaphAddAlt(ctx, "JA", "A");
            }
            else
            {
                MetaphAddAlt(ctx, "J", "A");
            }
        }
        else
        {
            if (ctx->m_encodeVowels)
            {
                MetaphAdd(ctx, "JA");
            }
            else
            {
                MetaphAdd(ctx, "J");
            }
        }

        ctx->m_current++;
        ctx->m_current = SkipVowels(ctx, ctx->m_current);
        return false;
    }
    else
    {
        MetaphAdd(ctx, "J");
        ctx->m_current++;
        return true;
    }
}