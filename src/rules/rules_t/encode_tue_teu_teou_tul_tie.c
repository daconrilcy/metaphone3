#include "rules/rules_t/encode_tue_teu_teou_tul_tie.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"
#include "utils/advance_counter.h"

bool Encode_TUE_TEU_TEOU_TUL_TIE(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;

    // 'constituent', 'pasteur'
    if (StringAt(w, (m_current + 1), 4, "UENT", "") ||
        StringAt(w, (m_current - 4), 9, "RIGHTEOUS", "") ||
        StringAt(w, (m_current - 3), 7, "STATUTE", "") ||
        StringAt(w, (m_current - 3), 7, "AMATEUR", "")
        // e.g. "blastula", "pasteur"
        || (StringAt(w, (m_current - 1), 5, "NTULE", "NTULA", "STULE", "STULA", "STEUR", ""))
        // e.g. "statue"
        || (((m_current + 2) == m_last) && StringAt(w, m_current, 3, "TUE", ""))
        // e.g. "constituency"
        || StringAt(w, m_current, 5, "TUENC", "")
        // e.g. "statutory"
        || StringAt(w, (m_current - 3), 8, "STATUTOR", "")
        // e.g. "patience"
        || (((m_current + 5) == m_last) && StringAt(w, m_current, 6, "TIENCE", "")))
    {
        MetaphAddAlt(ctx, "X", "T");
        AdvanceCounter(ctx, 2, 1);
        return true;
    }

    return false;
}