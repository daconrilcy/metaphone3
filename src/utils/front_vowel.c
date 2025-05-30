#include "utils/front_vowel.h"
#include "utils/string_utils.h"

bool Front_Vowel(Metaphone3 *ctx, int at)
{
    if (((CharAt(ctx->m_inWord, at) == 'E') || (CharAt(ctx->m_inWord, at) == 'I') || (CharAt(ctx->m_inWord, at) == 'Y')))
    {
        return true;
    }

    return false;
}