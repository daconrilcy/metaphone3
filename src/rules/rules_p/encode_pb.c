#include "rules/rules_p/encode_pb.h"
#include "utils/string_utils.h"

void Encode_PB(Metaphone3 *ctx)
{
    // e.g. "campbell", "raspberry"
    // eat redundant 'P' or 'B'
    if (StringAt(ctx->m_inWord, (ctx->m_current + 1), 1, "P", "B", ""))
    {
        ctx->m_current += 2;
    }
    else
    {
        ctx->m_current++;
    }
}