#include "rules/rules_g/rules_gh/encode_gh.h"
#include "rules/rules_g/rules_gh/encode_gh_after_consonant.h"
#include "rules/rules_g/rules_gh/encode_initial_gh.h"
#include "rules/rules_g/rules_gh/encode_gh_to_j.h"
#include "rules/rules_g/rules_gh/encode_gh_to_h.h"
#include "rules/rules_g/rules_gh/encode_ught.h"
#include "rules/rules_g/rules_gh/encode_gh_h_part_of_other_word.h"
#include "rules/rules_g/rules_gh/encode_silent_gh.h"
#include "rules/rules_g/rules_gh/encode_gh_to_f.h"

#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_GH(Metaphone3 *ctx)
{
    if (ctx->m_inWord, (ctx->m_current + 1) == 'H')
    {
        if (
            Encode_GH_After_Consonant(ctx) ||
            Encode_Initial_GH(ctx) ||
            Encode_GH_To_J(ctx) ||
            Encode_GH_To_H(ctx) ||
            Encode_UGHT(ctx) ||
            Encode_GH_H_Part_Of_Other_Word(ctx) ||
            Encode_Silent_GH(ctx) ||
            Encode_GH_To_F(ctx))
        {
            return true;
        }

        MetaphAddExactApproxSimple(ctx, "G", "K");
        ctx->m_current += 2;
        return true;
    }

    return false;
}