#include "rules/rules_c/encode_ccia.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_CCIA(Metaphone3 *ctx)
{
    int cur = ctx->m_current;
    if (StringAt(ctx->m_inWord, cur + 1, 3, "CIA", ""))
    {
        MetaphAddAlt(ctx, "X", "S");
        ctx->m_current += 2; // saute les 2 premiers "C" (le "C" courant et le suivant)
        return true;
    }
    return false;
}
