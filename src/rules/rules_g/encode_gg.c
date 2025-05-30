#include "rules/rules_g/encode_gg.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"
#include "utils/advance_counter.h"

bool Encode_GG(Metaphone3 *ctx)
{
    int cur = ctx->m_current;
    int last = ctx->m_last;
    const char *w = ctx->m_inWord;

    if (CharAt(w, cur + 1) == 'G')
    {
        // italian e.g, 'loggia', 'caraveggio', also 'suggest' and 'exaggerate'
        if (StringAt(w, (cur - 1), 5, "AGGIA", "OGGIA", "AGGIO", "EGGIO", "EGGIA", "IGGIO", "") ||
            // 'ruggiero' but not 'snuggies'
            (StringAt(w, (cur - 1), 5, "UGGIE", "") && !(((cur + 3) == last) ||
                                                         ((cur + 4) == last))) ||
            (((cur + 2) == last) && StringAt(w, (cur - 1), 4, "AGGI", "OGGI", "")) ||
            StringAt(w, (cur - 2), 6, "SUGGES", "XAGGER", "REGGIE", ""))
        {
            // expection where "-GG-" => KJ
            if (StringAt(w, (cur - 2), 7, "SUGGEST", ""))
            {
                MetaphAddExactApproxSimple(ctx, "G", "K");
            }

            MetaphAdd(ctx, "J");
            AdvanceCounter(ctx, 3, 2);
        }
        else
        {
            MetaphAddExactApproxSimple(ctx, "G", "K");
            ctx->m_current += 2;
        }
        return true;
    }

    return false;
}