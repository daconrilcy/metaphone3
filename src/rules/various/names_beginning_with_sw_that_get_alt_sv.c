#include "rules/various/names_beginning_with_sw_that_get_alt_sv.h"
#include "utils/string_utils.h"

bool Names_Beginning_With_SW_That_Get_Alt_SV(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;

    if (StringAt(w, 0, 7, "SWANSON", "SWENSON", "SWINSON", "SWENSEN", "SWOBODA", "") ||
        StringAt(w, 0, 9, "SWIDERSKI", "SWARTHOUT", "") ||
        StringAt(w, 0, 10, "SWEARENGIN", ""))
    {
        return true;
    }

    return false;
}