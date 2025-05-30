#include "rules/rules_x/encode_x.h"
#include "rules/rules_x/encode_french_x_final.h"
#include "rules/rules_x/encode_greek_x.h"
#include "rules/rules_x/encode_initial_x.h"
#include "rules/rules_x/encode_x_special_cases.h"
#include "rules/rules_x/encode_x_to_h.h"
#include "rules/rules_x/encode_x_vowel.h"

#include "utils/string_utils.h"

void Encode_X(Metaphone3 *ctx)
{
    if (Encode_Initial_X(ctx) ||
        Encode_Greek_X(ctx) ||
        Encode_X_Special_Cases(ctx) ||
        Encode_X_To_H(ctx) ||
        Encode_X_Vowel(ctx) ||
        Encode_French_X_Final(ctx))
    {
        return;
    }

    // eat redundant 'X' or other redundant cases
    if (StringAt(ctx->m_inWord, (ctx->m_current + 1), 1, "X", "Z", "S", "")
        // e.g. "excite", "exceed"
        || StringAt(ctx->m_inWord, (ctx->m_current + 1), 2, "CI", "CE", ""))
    {
        ctx->m_current += 2;
    }
    else
    {
        ctx->m_current++;
    }
}