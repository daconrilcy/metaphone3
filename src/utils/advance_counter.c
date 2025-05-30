#include "utils/advance_counter.h"

void AdvanceCounter(Metaphone3 *ctx, int ifNotEncodeVowels, int ifEncodeVowels)
{
    if (!ctx->m_encodeVowels)
    {
        ctx->m_current += ifNotEncodeVowels;
    }
    else
    {
        ctx->m_current += ifEncodeVowels;
    }
}
