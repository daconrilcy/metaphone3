#include "rules/rules_c/rules_front_vowel/encode_latinate_suffixes.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_Latinate_Suffixes(Metaphone3 *ctx)
{
    int cur = ctx->m_current;
    const char *w = ctx->m_inWord;

    if (StringAt(w, cur + 1, 4, "EOUS", "IOUS", ""))
    {
        MetaphAddAlt(ctx, "X", "S");
        return true;
    }

    return false;
}
