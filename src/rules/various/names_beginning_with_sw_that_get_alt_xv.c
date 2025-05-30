#include "rules/various/names_beginning_with_sw_that_get_alt_xv.h"
#include "utils/string_utils.h"

bool Names_Beginning_With_SW_That_Get_Alt_XV(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;

    if (StringAt(w, 0, 5, "SWART", "") ||
        StringAt(w, 0, 6, "SWARTZ", "SWARTS", "SWIGER", "") ||
        StringAt(w, 0, 7, "SWITZER", "SWANGER", "SWIGERT", "SWIGART", "SWIHART", "") ||
        StringAt(w, 0, 8, "SWEITZER", "SWATZELL", "SWINDLER", "") ||
        StringAt(w, 0, 9, "SWINEHART", "") ||
        StringAt(w, 0, 10, "SWEARINGEN", ""))
    {
        return true;
    }

    return false;
}