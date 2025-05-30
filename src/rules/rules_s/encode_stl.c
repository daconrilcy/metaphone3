#include "rules/rules_s/encode_stl.h"
#include "utils/string_utils.h"

bool Encode_STL(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    //'hustle', 'bustle', 'whistle'
    if ((StringAt(w, m_current, 4, "STLE", "STLI", "") &&
         !StringAt(w, (m_current + 2), 4, "LESS", "LIKE", "LINE", "")) ||
        StringAt(w, (m_current - 3), 7, "THISTLY", "BRISTLY", "GRISTLY", "")
        // e.g. "corpuscle"
        || StringAt(w, (m_current - 1), 5, "USCLE", ""))
    {
        // KRISTEN, KRYSTLE, CRYSTLE, KRISTLE all pronounce the 't'
        // also, exceptions where "-LING" is a nominalizing suffix
        if (StringAt(w, 0, 7, "KRISTEN", "KRYSTLE", "CRYSTLE", "KRISTLE", "") ||
            StringAt(w, 0, 11, "CHRISTENSEN", "CHRISTENSON", "") ||
            StringAt(w, (m_current - 3), 9, "FIRSTLING", "") ||
            StringAt(w, (m_current - 2), 8, "NESTLING", "WESTLING", ""))
        {
            MetaphAdd(ctx, "ST");
            ctx->m_current += 2;
        }
        else
        {
            if (ctx->m_encodeVowels && (CharAt(w, (m_current + 3)) == 'E') &&
                (CharAt(w, (m_current + 4)) != 'R') &&
                !StringAt(w, (m_current + 3), 4, "ETTE", "ETTA", "") &&
                !StringAt(w, (m_current + 3), 2, "EY", ""))
            {
                MetaphAdd(ctx, "SAL");
                ctx->flag_AL_inversion = true;
            }
            else
            {
                MetaphAdd(ctx, "SL");
            }
            ctx->m_current += 3;
        }
        return true;
    }

    return false;
}