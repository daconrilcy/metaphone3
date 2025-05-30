#include "rules/rules_c/rules_front_vowel/encode_british_silent_ce.h"
#include "utils/string_utils.h"

bool Encode_British_Silent_CE(Metaphone3 *ctx)
{
    int cur = ctx->m_current;
    int last = ctx->m_last;
    const char *w = ctx->m_inWord;

    if (
        (StringAt(w, cur + 1, 5, "ESTER", "") && (cur + 5 == last)) || StringAt(w, cur + 1, 10, "ESTERSHIRE", ""))
    {
        return true;
    }
    return false;
}
