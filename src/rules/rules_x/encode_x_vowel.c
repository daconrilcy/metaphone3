#include "rules/rules_x/encode_x_vowel.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"
#include "utils/advance_counter.h"

bool Encode_X_Vowel(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    // e.g. "sexual", "connexion" (british), "noxious"
    if (StringAt(w, (m_current + 1), 3, "UAL", "ION", "IOU", ""))
    {
        MetaphAddAlt(ctx, "KX", "KS");
        AdvanceCounter(ctx, 3, 1);
        return true;
    }

    return false;
}