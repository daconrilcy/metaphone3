#include "rules/rules_w/encode_wr.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"
#include "utils/advance_counter.h"

bool Encode_WR(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    // can also be in middle of word
    if (StringAt(w, m_current, 2, "WR", ""))
    {
        MetaphAdd(ctx, "R");
        ctx->m_current += 2;
        return true;
    }

    return false;
}