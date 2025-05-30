#include "rules/rules_e/e_pronouncing_suffix.h"
#include "utils/string_utils.h"

bool E_Pronouncing_Suffix(Metaphone3 *ctx, int at)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_length = ctx->m_length;
    int m_last = ctx->m_last;

    // e.g. 'bridgewood' - the other vowels will get eaten
    // up so we need to put one in here
    if ((m_length == (at + 4)) && StringAt(w, at, 4, "WOOD", ""))
    {
        return true;
    }

    // same as above
    if ((m_length == (at + 5)) && StringAt(w, at, 5, "WATER", "WORTH", ""))
    {
        return true;
    }

    // e.g. 'bridgette'
    if ((m_length == (at + 3)) && StringAt(w, at, 3, "TTE", "LIA", "NOW", "ROS", "RAS", ""))
    {
        return true;
    }

    // e.g. 'olena'
    if ((m_length == (at + 2)) && StringAt(w, at, 2, "TA", "TT", "NA", "NO", "NE", "RS", "RE", "LA", "AU", "RO", "RA", ""))
    {
        return true;
    }

    // e.g. 'bridget'
    if ((m_length == (at + 1)) && StringAt(w, at, 1, "T", "R", ""))
    {
        return true;
    }

    return false;
}