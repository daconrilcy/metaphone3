#include "rules/rules_t/encode_tient.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"
#include "utils/advance_counter.h"

bool Encode_TIENT(Metaphone3 *ctx)
{
    // e.g. 'patient'
    if (StringAt(ctx->m_inWord, (ctx->m_current + 1), 4, "IENT", ""))
    {
        MetaphAddAlt(ctx, "X", "T");
        AdvanceCounter(ctx, 3, 1);
        return true;
    }

    return false;
}
