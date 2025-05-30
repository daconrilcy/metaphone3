#include "rules/rules_j/encode_j.h"
#include "rules/rules_j/encode_spanish_j.h"
#include "rules/rules_j/encode_spanish_oj_uj.h"
#include "rules/rules_j/rules_other_j/encode_other_j.h"

void Encode_J(Metaphone3 *ctx)
{
    if (Encode_Spanish_J(ctx) || Encode_Spanish_OJ_UJ(ctx))
    {
        return;
    }

    Encode_Other_J(ctx);
}