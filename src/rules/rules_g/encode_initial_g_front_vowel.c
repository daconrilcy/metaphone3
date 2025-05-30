#include "rules/rules_g/encode_initial_g_front_vowel.h"
#include "utils/string_utils.h"
#include "utils/front_vowel.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"

bool Encode_Initial_G_Front_Vowel(Metaphone3 *ctx)
{
    int m_current = ctx->m_current;
    int m_length = ctx->m_length;
    const char *w = ctx->m_inWord;

    // 'g' followed by vowel at beginning
    if ((m_current == 0) && Front_Vowel(ctx, m_current + 1))
    {
        // special case "gila" as in "gila monster"
        if (StringAt(w, (m_current + 1), 3, "ILA", "") && (m_length == 4))
        {
            MetaphAdd(ctx, "H");
        }
        else if (Initial_G_Soft(ctx))
        {
            MetaphAddExactApprox(ctx, "J", "G", "J", "K");
        }
        else
        {
            // only code alternate 'J' if front vowel
            if ((charAt(w, (m_current + 1)) == 'E') || (charAt(w, (m_current + 1)) == 'I'))
            {
                MetaphAddExactApprox(ctx, "G", "J", "K", "J");
            }
            else
            {
                MetaphAddExactApproxSimple(ctx, "G", "K");
            }
        }

        AdvanceCounter(ctx, 2, 1);
        return true;
    }

    return false;
}