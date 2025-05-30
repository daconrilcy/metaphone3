#include "rules/rules_g/rules_internal_hard_g/encode_hard_g.h"
#include "rules/rules_g/rules_internal_hard_g/encode_internal_hard_g_other.h"
#include "rules/rules_g/rules_internal_hard_g/encode_internal_hard_g_open_syllable.h"
#include "rules/rules_g/rules_internal_hard_g/encode_hard_gen_gin_get_git.h"

#include "utils/string_utils.h"

bool Internal_Hard_G(Metaphone3 *ctx)
{
    int m_current = ctx->m_current;
    int m_last = ctx->m_last;
    const char *w = ctx->m_inWord;

    // if not "-GE" at end
    if (!(((m_current + 1) == m_last) &&
          (CharAt(w, (m_current + 1)) == 'E')) &&
        (Internal_Hard_NG(ctx) ||
         Internal_Hard_GEN_GIN_GET_GIT(ctx) ||
         Internal_Hard_G_Open_Syllable(ctx) ||
         Internal_Hard_G_Other(ctx)))
    {
        return true;
    }

    return false;
}