#include "rules/rules_z/encode_zh.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_ZH(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    // chinese pinyin e.g. 'zhao', also english "phonetic spelling"
    if (CharAt(ctx->m_inWord, (ctx->m_current + 1)) == 'H')
    {
        MetaphAdd(ctx, "J");
        ctx->m_current += 2;
        return true;
    }

    return false;
}