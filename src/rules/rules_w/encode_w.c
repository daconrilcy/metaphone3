#include "rules/rules_w/encode_w.h"
#include "rules/rules_w/encode_eastern_european_w.h"
#include "rules/rules_w/encode_initial_w_vowel.h"
#include "rules/rules_w/encode_silent_w_at_beginning.h"
#include "rules/rules_w/encode_wh.h"
#include "rules/rules_w/encode_witz_wicz.h"
#include "rules/rules_w/encode_wr.h"

#include "utils/string_utils.h"
#include "utils/metaph_add.h"

void Encode_W(Metaphone3 *ctx)
{
    if (Encode_Silent_W_At_Beginning(ctx) ||
        Encode_WITZ_WICZ(ctx) ||
        Encode_WR(ctx) ||
        Encode_Initial_W_Vowel(ctx) ||
        Encode_WH(ctx) ||
        Encode_Eastern_European_W(ctx))
    {
        return;
    }

    // e.g. 'zimbabwe'
    if (ctx->m_encodeVowels && StringAt(ctx->m_inWord, ctx->m_current, 2, "WE", "") && ((ctx->m_current + 1) == ctx->m_last))
    {
        MetaphAdd(ctx, "A");
    }

    // else skip it
    ctx->m_current++;
}