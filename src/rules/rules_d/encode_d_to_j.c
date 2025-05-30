#include "rules/rules_d/encode_d_to_j.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"

bool Encode_D_To_J(Metaphone3 *ctx)
{
    int cur = ctx->m_current;
    int last = ctx->m_last;
    const char *w = ctx->m_inWord;

    // e.g. "module", "adulate"
    if ((StringAt(w, cur, 3, "DUL", "") && (IsVowel(CharAt(w, (cur - 1))) && IsVowel(CharAt(w, (cur + 3)))))
        // e.g. "soldier", "grandeur", "procedure"
        || (((cur + 3) == last) && StringAt(w, (cur - 1), 5, "LDIER", "NDEUR", "EDURE", "RDURE", "")) || StringAt(w, (cur - 3), 7, "CORDIAL", "")
        // e.g.  "pendulum", "education"
        || StringAt(w, (cur - 1), 5, "NDULA", "NDULU", "EDUCA", "")
        // e.g. "individual", "individual", "residuum"
        || StringAt(w, (cur - 1), 4, "ADUA", "IDUA", "IDUU", ""))
    {
        MetaphAddExactApprox(ctx, "J", "D", "J", "T");
        AdvanceCounter(ctx, 2, 1);
        return true;
    }

    return false;
}