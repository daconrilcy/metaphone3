#include "rules/rules_p/encode_psych.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_PSYCH(Metaphone3 *ctx)
{
    //'-psych-'
    if (StringAt(ctx->m_inWord, (ctx->m_current + 1), 4, "SYCH", ""))
    {
        if (ctx->m_encodeVowels)
        {
            MetaphAdd(ctx, "SAK");
        }
        else
        {
            MetaphAdd(ctx, "SK");
        }

        ctx->m_current += 5;
        return true;
    }

    return false;
}