#include "rules/rules_p/encode_psalm.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_PSALM(Metaphone3 *ctx)
{
    //'-psalm-'
    if (StringAt(ctx->m_inWord, (ctx->m_current + 1), 4, "SALM", ""))
    {
        // go ahead and encode entire word
        if (ctx->m_encodeVowels)
        {
            MetaphAdd(ctx, "SAM");
        }
        else
        {
            MetaphAdd(ctx, "SM");
        }

        ctx->m_current += 5;
        return true;
    }

    return false;
}