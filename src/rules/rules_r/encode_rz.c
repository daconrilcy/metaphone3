#include "rules/rules_r/encode_rz.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_RZ(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;

    if (StringAt(w, (m_current - 2), 4, "GARZ", "KURZ", "MARZ", "MERZ", "HERZ", "PERZ", "WARZ", "") ||
        StringAt(w, m_current, 5, "RZANO", "RZOLA", "") ||
        StringAt(w, (m_current - 1), 4, "ARZA", "ARZN", ""))
    {
        return false;
    }

    // 'yastrzemski' usually has 'z' silent in
    // united states, but should get 'X' in poland
    if (StringAt(w, (m_current - 4), 11, "YASTRZEMSKI", ""))
    {
        MetaphAddAlt(ctx, "R", "X");
        ctx->m_current += 2;
        return true;
    }
    // 'BRZEZINSKI' gets two pronunciations
    // in the united states, neither of which
    // are authentically polish
    if (StringAt(w, (m_current - 1), 10, "BRZEZINSKI", ""))
    {
        MetaphAddAlt(ctx, "RS", "RJ");
        // skip over 2nd 'Z'
        ctx->m_current += 4;
        return true;
    }
    // 'z' in 'rz after voiceless consonant gets 'X'
    // in alternate polish style pronunciation
    else if (StringAt(w, (m_current - 1), 3, "TRZ", "PRZ", "KRZ", "") ||
             (StringAt(w, m_current, 2, "RZ", "") &&
              (IsVowel(CharAt(w, (m_current - 1))) || (m_current == 0))))
    {
        MetaphAddAlt(ctx, "RS", "X");
        ctx->m_current += 2;
        return true;
    }
    // 'z' in 'rz after voiceled consonant, vowel, or at
    // beginning gets 'J' in alternate polish style pronunciation
    else if (StringAt(w, (m_current - 1), 3, "BRZ", "DRZ", "GRZ", ""))
    {
        MetaphAddAlt(ctx, "RS", "J");
        ctx->m_current += 2;
        return true;
    }

    return false;
}