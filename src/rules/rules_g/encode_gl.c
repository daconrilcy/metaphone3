#include "rules/rules_g/encode_gl.h"
#include "utils/string_utils.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"

bool Encode_GL(Metaphone3 *ctx)
{
    //'tagliaro', 'puglia' BUT add K in alternative
    // since americans sometimes do this
    if (StringAt(ctx->m_inWord, (ctx->m_current + 1), 3, "LIA", "LIO", "LIE", "") && IsVowel(CharAt(ctx->m_inWord, (ctx->m_current - 1))))
    {
        MetaphAddExactApprox(ctx, "L", "GL", "L", "KL");
        ctx->m_current += 2;
        return true;
    }

    return false;
}