#include "rules/rules_c/rules_ch/encode_chae.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"
#include "utils/advance_counter.h"

bool Encode_CHAE(Metaphone3 *ctx)
{
    int cur = ctx->m_current;
    // e.g. 'michael' : "-CHAE-"
    if ((cur > 0) && StringAt(ctx->m_inWord, cur + 2, 2, "AE", ""))
    {
        if (StringAt(ctx->m_inWord, 0, 7, "RACHAEL", ""))
        {
            MetaphAdd(ctx, "X");
        }
        else if (!StringAt(ctx->m_inWord, cur - 1, 1, "C", "K", "G", "Q", ""))
        {
            MetaphAdd(ctx, "K");
        }
        AdvanceCounter(ctx, 4, 2);
        return true;
    }
    return false;
}
