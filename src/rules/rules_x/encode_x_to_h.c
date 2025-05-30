#include "rules/rules_x/encode_x_to_h.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_X_To_H(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    // TODO: look for other mexican indian words
    // where 'X' is usually pronounced this way
    if (StringAt(w, (m_current - 2), 6, "OAXACA", "") || StringAt(w, (m_current - 3), 7, "QUIXOTE", ""))
    {
        MetaphAdd(ctx, "H");
        ctx->m_current++;
        return true;
    }

    return false;
}