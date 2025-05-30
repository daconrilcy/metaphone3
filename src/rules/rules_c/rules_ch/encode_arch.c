#include "rules/rules_c/rules_ch/encode_arch.h"
#include "utils/string_utils.h"
#include "utils/char_utils.h"
#include "utils/root_or_inflections.h"
#include "utils/metaph_add.h"

bool Encode_ARCH(Metaphone3 *ctx)
{
    int cur = ctx->m_current, last = ctx->m_last;
    const char *word = ctx->m_inWord;
    bool is_arch = false;

    // "-ARCH-"
    if (cur >= 2 && StringAt(word, cur - 2, 4, "ARCH", ""))
    {
        // Patterns d'origine grecque
        if (
            (
                (IsVowel(CharAt(word, cur + 2)) &&
                 StringAt(word, cur - 2, 5, "ARCHA", "ARCHI", "ARCHO", "ARCHU", "ARCHY", "")) ||
                StringAt(word, cur - 2, 6, "ARCHEA", "ARCHEG", "ARCHEO", "ARCHET", "ARCHEL", "ARCHES",
                         "ARCHEP", "ARCHEM", "ARCHEN", "") ||
                (StringAt(word, cur - 2, 4, "ARCH", "") && ((cur + 1) == last)) || StringAt(word, 0, 7, "MENARCH", "")) &&
            !RootOrInflections(word, "ARCH") && !(cur >= 4 && StringAt(word, cur - 4, 6, "SEARCH", "POARCH", "")) && !StringAt(word, 0, 9, "ARCHENEMY", "ARCHIBALD", "ARCHULETA", "ARCHAMBAU", "") && !StringAt(word, 0, 6, "ARCHER", "ARCHIE", "") && !(((cur >= 3 && StringAt(word, cur - 3, 5, "LARCH", "MARCH", "PARCH", "")) || (cur >= 4 && StringAt(word, cur - 4, 6, "STARCH", ""))) && !(StringAt(word, 0, 6, "EPARCH", "") || StringAt(word, 0, 7, "NOMARCH", "") || StringAt(word, 0, 8, "EXILARCH", "HIPPARCH", "MARCHESE", "") || StringAt(word, 0, 9, "ARISTARCH", "MARCHETTI", ""))) && !RootOrInflections(word, "STARCH") && (!(StringAt(word, cur - 2, 5, "ARCHU", "ARCHY", "") && !StringAt(word, 0, 7, "STARCHY", ""))))
        {
            MetaphAddAlt(ctx, "K", "X");
        }
        else
        {
            MetaphAdd(ctx, "X");
        }
        ctx->m_current += 2;
        return true;
    }
    return false;
}
