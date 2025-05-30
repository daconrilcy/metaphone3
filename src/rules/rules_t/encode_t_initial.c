#include "rules/rules_t/encode_t_initial.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"
#include "utils/advance_counter.h"

bool Encode_T_Initial(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_length = ctx->m_length;

    if (m_current == 0)
    {
        // americans usually pronounce "tzar" as "zar"
        if (StringAt(w, (m_current + 1), 3, "SAR", "ZAR", ""))
        {
            ctx->m_current++;
            return true;
        }

        // old 'École française d'Extręme-Orient' chinese pinyin where 'ts-' => 'X'
        if (((m_length == 3) && StringAt(w, (m_current + 1), 2, "SO", "SA", "SU", "")) ||
            ((m_length == 4) && StringAt(w, (m_current + 1), 3, "SAO", "SAI", "")) ||
            ((m_length == 5) && StringAt(w, (m_current + 1), 4, "SING", "SANG", "")))
        {
            MetaphAdd(ctx, "X");
            AdvanceCounter(ctx, 3, 2);
            return true;
        }

        // "TS<vowel>-" at start can be pronounced both with and without 'T'
        if (StringAt(w, (m_current + 1), 1, "S", "") && IsVowel(CharAt(w, (m_current + 2))))
        {
            MetaphAddAlt(ctx, "TS", "S");
            AdvanceCounter(ctx, 3, 2);
            return true;
        }

        // e.g. "Tjaarda"
        if (StringAt(w, (m_current + 1), 1, "J", ""))
        {
            MetaphAdd(ctx, "X");
            AdvanceCounter(ctx, 3, 2);
            return true;
        }

        // cases where initial "TH-" is pronounced as T and not 0 ("th")
        if ((StringAt(w, (m_current + 1), 2, "HU", "") && (m_length == 3)) ||
            StringAt(w, (m_current + 1), 3, "HAI", "HUY", "HAO", "") ||
            StringAt(w, (m_current + 1), 4, "HYME", "HYMY", "HANH", "") ||
            StringAt(w, (m_current + 1), 5, "HERES", ""))
        {
            MetaphAdd(ctx, "T");
            AdvanceCounter(ctx, 3, 2);
            return true;
        }
    }

    return false;
}