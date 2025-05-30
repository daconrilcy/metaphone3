#include "rules/rules_z/encode_z.h"
#include "rules/rules_z/encode_french_ez.h"
#include "rules/rules_z/encode_german_z.h"
#include "rules/rules_z/encode_zh.h"
#include "rules/rules_z/encode_zu_zier_zs.h"
#include "rules/rules_z/encode_zz.h"

#include "utils/string_utils.h"

void Encode_Z(Metaphone3 *ctx)
{
    if (Encode_ZZ(ctx) ||
        Encode_ZU_ZIER_ZS(ctx) ||
        Encode_French_EZ(ctx) ||
        Encode_German_Z(ctx))
    {
        return;
    }

    if (Encode_ZH(ctx))
    {
        return;
    }
    else
    {
        MetaphAdd(ctx, "S");
    }

    // eat redundant 'Z'
    if (CharAt(ctx->m_inWord, (ctx->m_current + 1)) == 'Z')
    {
        ctx->m_current += 2;
    }
    else
    {
        ctx->m_current++;
    }
}