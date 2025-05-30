#include "rules/rules_g/encode_non_initial_g_front_vowel.h"
#include "rules/rules_g/rules_internal_hard_g/encode_hard_g.h"
#include "rules/rules_g/encode_hard_ge_at_end.h"
#include "utils/string_utils.h"
#include "utils/slavo_germanic.h"
#include "utils/metaph_add.h"
#include "utils/advance_counter.h"

bool Encode_Non_Initial_G_Front_Vowel(Metaphone3 *ctx)
{
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;
    const char *w = ctx->m_inWord;

    // -gy-, gi-, ge-
    if (StringAt(w, (m_current + 1), 1, "E", "I", "Y", ""))
    {
        // '-ge' at end
        // almost always 'j 'sound
        if (StringAt(w, m_current, 2, "GE", "") && (m_current == (m_last - 1)))
        {
            if (Hard_GE_At_End(ctx))
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
                MetaphAdd(ctx, "J");
            }
        }
        else
        {
            if (Internal_Hard_G(ctx))
            {
                // don't encode KG or KK if e.g. "mcgill"
                if (!((m_current == 2) && StringAt(w, 0, 2, "MC", "")) || ((m_current == 3) && StringAt(w, 0, 3, "MAC", "")))
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
            }
            else
            {
                MetaphAddExactApprox(ctx, "J", "G", "J", "K");
            }
        }

        AdvanceCounter(ctx, 2, 1);
        return true;
    }

    return false;
}