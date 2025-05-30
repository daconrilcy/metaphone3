#include "rules/rules_c/rules_front_vowel/encode_ce.h"
#include "utils/string_utils.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"

bool Encode_CE(Metaphone3 *ctx)
{
    int cur = ctx->m_current;
    int last = ctx->m_last;
    const char *w = ctx->m_inWord;

    if (
        // 'ocean' (voyelle avant)
        (StringAt(w, cur + 1, 3, "EAN", "") && IsVowel(CharAt(w, cur - 1)))
        // 'rosacea'
        || (cur >= 1 && StringAt(w, cur - 1, 4, "ACEA", "") && ((cur + 2) == last) && !StringAt(w, 0, 7, "PANACEA", ""))
        // 'botticelli', 'concerto'
        || StringAt(w, cur + 1, 4, "ELLI", "ERTO", "EORL", "")
        // italien : 'croce'
        || (cur >= 3 && StringAt(w, cur - 3, 5, "CROCE", "") && ((cur + 1) == last)) || (cur >= 3 && StringAt(w, cur - 3, 5, "DOLCE", ""))
        // 'cello'
        || (StringAt(w, cur + 1, 4, "ELLO", "") && ((cur + 4) == last)))
    {
        MetaphAddAlt(ctx, "X", "S");
        return true;
    }

    return false;
}
