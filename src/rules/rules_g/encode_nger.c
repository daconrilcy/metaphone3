#include "rules/rules_g/encode_nger.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"
#include "utils/advance_counter.h"
#include "utils/root_or_inflections.h"

bool Encode_NGER(Metaphone3 *ctx)
{
    const char *m_inWord = ctx->m_inWord;
    int m_current = ctx->m_current;

    if ((m_current > 1) && StringAt(m_inWord, (m_current - 1), 4, "NGER", ""))
    {
        // default 'G' => J  such as 'ranger', 'stranger', 'manger', 'messenger', 'orangery', 'granger'
        // 'boulanger', 'challenger', 'danger', 'changer', 'harbinger', 'lounger', 'ginger', 'passenger'
        // except for these the following
        if (!(RootOrInflections(m_inWord, "ANGER") ||
              RootOrInflections(m_inWord, "LINGER") ||
              RootOrInflections(m_inWord, "MALINGER") ||
              RootOrInflections(m_inWord, "FINGER") ||
              (StringAt(m_inWord, (m_current - 3), 4, "HUNG", "FING", "BUNG", "WING", "RING", "DING", "ZENG", "ZING", "JUNG", "LONG", "PING", "CONG", "MONG", "BANG", "GANG", "HANG", "LANG", "SANG", "SING", "WANG", "ZANG", "")
               // exceptions to above where 'G' => J
               && !(StringAt(m_inWord, (m_current - 6), 7, "BOULANG", "SLESING", "KISSING", "DERRING", "") ||
                    StringAt(m_inWord, (m_current - 8), 9, "SCHLESING", "") ||
                    StringAt(m_inWord, (m_current - 5), 6, "SALING", "BELANG", "") ||
                    StringAt(m_inWord, (m_current - 6), 7, "BARRING", "") ||
                    StringAt(m_inWord, (m_current - 6), 9, "PHALANGER", "") ||
                    StringAt(m_inWord, (m_current - 4), 5, "CHANG", ""))) ||
              StringAt(m_inWord, (m_current - 4), 5, "STING", "YOUNG", "") ||
              StringAt(m_inWord, (m_current - 5), 6, "STRONG", "") ||
              StringAt(m_inWord, 0, 3, "UNG", "ENG", "ING", "") ||
              StringAt(m_inWord, m_current, 6, "GERICH", "") ||
              StringAt(m_inWord, 0, 6, "SENGER", "") ||
              StringAt(m_inWord, (m_current - 3), 6, "WENGER", "MUNGER", "SONGER", "KINGER", "") ||
              StringAt(m_inWord, (m_current - 4), 7, "FLINGER", "SLINGER", "STANGER", "STENGER", "KLINGER", "CLINGER", "") ||
              StringAt(m_inWord, (m_current - 5), 8, "SPRINGER", "SPRENGER", "") ||
              StringAt(m_inWord, (m_current - 3), 7, "LINGERF", "") ||
              StringAt(m_inWord, (m_current - 2), 7, "ANGERLY", "ANGERBO", "INGERSO", "")))
        {
            MetaphAddExactApprox(ctx, "J", "G", "J", "K");
        }
        else
        {
            MetaphAddExactApprox(ctx, "G", "J", "K", "J");
        }

        AdvanceCounter(ctx, 2, 1);
        return true;
    }

    return false;
}