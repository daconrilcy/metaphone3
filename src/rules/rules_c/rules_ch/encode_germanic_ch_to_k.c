#include "rules/rules_c/rules_ch/encode_germanic_ch_to_k.h"
#include "utils/string_utils.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/slavo_germanic.h"

bool Encode_Germanic_CH_To_K(Metaphone3 *ctx)
{
    int cur = ctx->m_current, last = ctx->m_last;
    bool is_germanic = false;

    if ((cur > 1 && !IsVowel(CharAt(ctx->m_inWord, cur - 2)) && StringAt(ctx->m_inWord, cur - 1, 3, "ACH", "") && !(cur >= 2 && StringAt(ctx->m_inWord, cur - 2, 7, "MACHADO", "MACHUCA", "LACHANC", "LACHAPE", "KACHATU", "")) && !(cur >= 3 && StringAt(ctx->m_inWord, cur - 3, 7, "KHACHAT", "")) && ((CharAt(ctx->m_inWord, cur + 2) != 'I') && ((CharAt(ctx->m_inWord, cur + 2) != 'E') || (cur >= 2 && StringAt(ctx->m_inWord, cur - 2, 6, "BACHER", "MACHER", "MACHEN", "LACHER", "")))))
        // suite du if
        || (cur + 2 <= last && StringAt(ctx->m_inWord, cur + 2, 1, "T", "S", "") &&
            !(StringAt(ctx->m_inWord, 0, 11, "WHICHSOEVER", "") ||
              StringAt(ctx->m_inWord, 0, 9, "LUNCHTIME", ""))) ||
        StringAt(ctx->m_inWord, 0, 4, "SCHR", "") ||
        (cur > 2 && StringAt(ctx->m_inWord, cur - 2, 5, "MACHE", "")) ||
        (cur == 2 && StringAt(ctx->m_inWord, cur - 2, 4, "ZACH", "")) ||
        (cur >= 4 && StringAt(ctx->m_inWord, cur - 4, 6, "SCHACH", "")) ||
        (cur >= 1 && StringAt(ctx->m_inWord, cur - 1, 5, "ACHEN", "")) ||
        (cur >= 3 && StringAt(ctx->m_inWord, cur - 3, 5, "SPICH", "ZURCH", "BUECH", "")) ||
        (cur >= 3 && StringAt(ctx->m_inWord, cur - 3, 5, "KIRCH", "JOACH", "BLECH", "MALCH", "") && !(cur >= 3 && StringAt(ctx->m_inWord, cur - 3, 8, "KIRCHNER", "")) && !((cur + 1) == last)) ||
        ((cur + 1) == last && cur >= 2 && StringAt(ctx->m_inWord, cur - 2, 4, "NICH", "LICH", "BACH", "")) ||
        ((cur + 1) == last && cur >= 3 && StringAt(ctx->m_inWord, cur - 3, 5, "URICH", "BRICH", "ERICH", "DRICH", "NRICH", "") && !(cur >= 5 && StringAt(ctx->m_inWord, cur - 5, 7, "ALDRICH", "")) &&
         !(cur >= 6 && StringAt(ctx->m_inWord, cur - 6, 8, "GOODRICH", "")) && !(cur >= 7 && StringAt(ctx->m_inWord, cur - 7, 9, "GINGERICH", ""))) ||
        ((cur + 1) == last && cur >= 4 && StringAt(ctx->m_inWord, cur - 4, 6, "ULRICH", "LFRICH", "LLRICH", "EMRICH", "ZURICH", "EYRICH", "")) ||
        ((StringAt(ctx->m_inWord, cur - 1, 1, "A", "O", "U", "E", "") || (cur == 0)) && StringAt(ctx->m_inWord, cur + 2, 1, "L", "R", "N", "M", "B", "H", "F", "V", "W", " ", "")))
    {
        // cas spéciaux : "CHR/L-"
        if (StringAt(ctx->m_inWord, cur + 2, 1, "R", "L", "") || SlavoGermanic(ctx))
        {
            MetaphAdd(ctx, "K");
        }
        else
        {
            MetaphAddAlt(ctx, "K", "X");
        }
        ctx->m_current += 2;
        return true;
    }
    return false;
}
