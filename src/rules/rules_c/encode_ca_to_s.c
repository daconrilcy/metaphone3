#include "rules/rules_c/encode_ca_to_s.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"
#include "utils/advance_counter.h"

bool Encode_CA_To_S(Metaphone3 *ctx)
{
    if (
        // cas spéciaux au début du mot
        (ctx->m_current == 0 && StringAt(ctx->m_inWord, ctx->m_current, 4, "CAES", "CAEC", "CAEM", ""))
        // ou dans tout le mot
        || StringAt(ctx->m_inWord, 0, 8, "FRANCAIS", "FRANCAIX", "LINGUICA", "") || StringAt(ctx->m_inWord, 0, 6, "FACADE", "") || StringAt(ctx->m_inWord, 0, 9, "GONCALVES", "PROVENCAL", ""))
    {
        MetaphAdd(ctx, "S");
        AdvanceCounter(ctx, 2, 1);
        return true;
    }
    return false;
}
