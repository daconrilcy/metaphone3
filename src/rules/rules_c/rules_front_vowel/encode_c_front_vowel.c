#include "rules/rules_c/rules_front_vowel/encode_c_front_vowel.h"
#include "utils/string_utils.h"
#include "rules/rules_c/rules_front_vowel/encode_british_silent_ce.h"
#include "rules/rules_c/rules_front_vowel/encode_ce.h"
#include "rules/rules_c/rules_front_vowel/encode_ci.h"
#include "rules/rules_c/rules_front_vowel/encode_latinate_suffixes.h"
#include "utils/metaph_add.h"

// Simule AdvanceCounter(n, m) (logique : avance de m)
static void AdvanceCounter(Metaphone3 *ctx, int n, int m)
{
    ctx->m_current += m;
}

bool Encode_C_Front_Vowel(Metaphone3 *ctx)
{
    int cur = ctx->m_current;
    const char *w = ctx->m_inWord;

    if (StringAt(w, cur, 2, "CI", "CE", "CY", ""))
    {
        if (
            Encode_British_Silent_CE(ctx) ||
            Encode_CE(ctx) ||
            Encode_CI(ctx) ||
            Encode_Latinate_Suffixes(ctx))
        {
            AdvanceCounter(ctx, 2, 1);
            return true;
        }
        MetaphAdd(ctx, "S");
        AdvanceCounter(ctx, 2, 1);
        return true;
    }
    return false;
}