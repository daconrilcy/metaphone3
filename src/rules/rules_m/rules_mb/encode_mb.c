#include "rules/rules_m/rules_mb/encode_mb.h"
#include "rules/rules_m/rules_mb/test_mn.h"
#include "rules/rules_m/rules_mb/test_pronounced_mb.h"
#include "rules/rules_m/rules_mb/test_silent_mb_1.h"
#include "rules/rules_m/rules_mb/test_pronounced_mb_2.h"
#include "rules/rules_m/rules_mb/test_silent_mb_2.h"

#include "utils/string_utils.h"

bool Encode_MB(Metaphone3 *ctx)
{
    if (Test_Silent_MB_1(ctx))
    {
        if (Test_Pronounced_MB(ctx))
        {
            ctx->m_current++;
        }
        else
        {
            ctx->m_current += 2;
        }
    }
    else if (Test_Silent_MB_2(ctx))
    {
        if (Test_Pronounced_MB_2(ctx))
        {
            ctx->m_current++;
        }
        else
        {
            ctx->m_current += 2;
        }
    }
    else if (Test_MN(ctx))
    {
        ctx->m_current += 2;
    }
    else
    {
        // eat redundant 'M'
        if (CharAt(ctx->m_inWord, (ctx->m_current + 1)) == 'M')
        {
            ctx->m_current += 2;
        }
        else
        {
            ctx->m_current++;
        }
    }
}