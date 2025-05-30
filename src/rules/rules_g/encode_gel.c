#include "rules/rules_g/encode_gel.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"
#include "utils/slavo_germanic.h"

bool Encode_GEL(Metaphone3 *ctx)
{
    int m_current = ctx->m_current;
    int m_length = ctx->m_length;
    const char *w = ctx->m_inWord;

    // more likely to be "-GEL-" => JL
    if (StringAt(w, (m_current + 1), 2, "EL", "") && (m_current > 0))
    {
        // except for
        // "BAGEL", "HEGEL", "HUGEL", "KUGEL", "NAGEL", "VOGEL", "FOGEL", "PAGEL"
        if (((m_length == 5) && IsVowel(CharAt(w, (m_current - 1))) &&
             !IsVowel(CharAt(w, (m_current - 2))) && !StringAt(w, (m_current - 2), 5, "NIGEL", "RIGEL", ""))
            // or the following as combining forms
            || StringAt(w, (m_current - 2), 5, "ENGEL", "HEGEL", "NAGEL", "VOGEL", "") ||
            StringAt(w, (m_current - 3), 6, "MANGEL", "WEIGEL", "FLUGEL", "RANGEL", "HAUGEN", "RIEGEL", "VOEGEL", "") ||
            StringAt(w, (m_current - 4), 7, "SPEIGEL", "STEIGEL", "WRANGEL", "SPIEGEL", "") ||
            StringAt(w, (m_current - 4), 8, "DANEGELD", ""))
        {
            if (SlavoGermanic(ctx))
            {
                MetaphAddExactApproxSimple(ctx, "G", "K");
            }
            else
            {
                MetaphAddExactApprox(ctx, "G", "J", "K", "J");
            }
        }
        else
        {
            MetaphAddExactApprox(ctx, "J", "G", "J", "K");
        }

        AdvanceCounter(ctx, 2, 1);
        return true;
    }

    return false;
}