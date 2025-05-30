#include "rules/rules_r/encode_r.h"
#include "rules/rules_r/encode_rz.h"
#include "rules/rules_r/encode_vowel_re_transposition.h"
#include "rules/rules_r/test_silent_r.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

void Encode_R(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    if (Encode_RZ(ctx))
    {
        return;
    }

    if (!Test_Silent_R(ctx))
    {
        if (!Encode_Vowel_RE_Transposition(ctx))
        {
            MetaphAdd(ctx, "R");
        }
    }

    // eat redundant 'R'; also skip 'S' as well as 'R' in "poitiers"
    if ((CharAt(w, (m_current + 1)) == 'R') || StringAt(w, (m_current - 6), 8, "POITIERS", ""))
    {
        ctx->m_current += 2;
    }
    else
    {
        ctx->m_current++;
    }
}