#include "rules/rules_g/encode_ger.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"
#include "utils/slavo_germanic.h"
#include "utils/advance_counter.h"

bool Encode_GER(Metaphone3 *ctx)
{
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;
    int m_length = ctx->m_length;
    const char *w = ctx->m_inWord;

    if ((m_current > 0) && StringAt(w, (m_current + 1), 2, "ER", ""))
    {
        // Exceptions to 'GE' where 'G' => K
        // e.g. "JAGER", "TIGER", "LIGER", "LAGER", "LUGER", "AUGER", "EAGER", "HAGER", "SAGER"
        if ((((m_current == 2) && IsVowel(CharAt(w, (m_current - 1))) &&
                  !IsVowel(CharAt(w, (m_current - 2))) && !(StringAt(w, (m_current - 2), 5, "PAGER", "WAGER", "NIGER", "ROGER", "LEGER", "CAGER", "")) ||
              StringAt(w, (m_current - 2), 5, "AUGER", "EAGER", "INGER", "YAGER", "")) ||
             StringAt(w, (m_current - 3), 6, "SEEGER", "JAEGER", "GEIGER", "KRUGER", "SAUGER", "BURGER", "MEAGER", "MARGER", "RIEGER", "YAEGER", "STEGER", "PRAGER", "SWIGER", "YERGER", "TORGER", "FERGER", "HILGER", "ZEIGER", "YARGER", "COWGER", "CREGER", "KROGER", "KREGER", "GRAGER", "STIGER", "BERGER", "")
             // 'berger' but not 'bergerac'
             || (StringAt(w, (m_current - 3), 6, "BERGER", "") && ((m_current + 2) == m_last)) ||
             StringAt(w, (m_current - 4), 7, "KREIGER", "KRUEGER", "METZGER", "KRIEGER", "KROEGER", "STEIGER", "DRAEGER", "BUERGER", "BOERGER", "FIBIGER", "")
             // e.g. 'harshbarger', 'winebarger'
             || (StringAt(w, (m_current - 3), 6, "BARGER", "") && (m_current > 4))
             // e.g. 'weisgerber'
             || (StringAt(w, m_current, 6, "GERBER", "") && (m_current > 0)) ||
             StringAt(w, (m_current - 5), 8, "SCHWAGER", "LYBARGER", "SPRENGER", "GALLAGER", "WILLIGER", "") ||
             StringAt(w, 0, 4, "HARGER", "") ||
             (StringAt(w, 0, 4, "AGER", "EGER", "") && (m_length == 4)) ||
             StringAt(w, (m_current - 1), 6, "YGERNE", "") ||
             StringAt(w, (m_current - 6), 9, "SCHWEIGER", "")) &&
            !(StringAt(w, (m_current - 5), 10, "BELLIGEREN", "") || StringAt(w, 0, 7, "MARGERY", "") || StringAt(w, (m_current - 3), 8, "BERGERAC", "")))
        {
            if (SlavoGermanic(ctx))
            {
                MetaphAddExactApproxSimple(ctx, "G", "K");
            }
            else
            {
                MetaphAddExactApprox(ctx, "G", "J", "K", "J");
            }
        }
        else
        {
            MetaphAddExactApprox(ctx, "J", "G", "J", "K");
        }

        AdvanceCounter(ctx, 2, 1);
        return true;
    }

    return false;
}