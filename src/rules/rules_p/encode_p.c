#include "rules/rules_p/encode_p.h"
#include "rules/rules_p/encode_coup.h"
#include "rules/rules_p/encode_pb.h"
#include "rules/rules_p/encode_ph.h"
#include "rules/rules_p/encode_pneum.h"
#include "rules/rules_p/encode_pph.h"
#include "rules/rules_p/encode_psalm.h"
#include "rules/rules_p/encode_psych.h"
#include "rules/rules_p/encode_pt.h"
#include "rules/rules_p/encode_rps.h"
#include "rules/rules_p/encode_silent_p_at_beginning.h"

#include "utils/metaph_add.h"

void Encode_P(Metaphone3 *ctx)
{
    if (
        Encode_Silent_P_At_Beginning(ctx) ||
        Encode_PT(ctx) ||
        Encode_PH(ctx) ||
        Encode_PPH(ctx) ||
        Encode_RPS(ctx) ||
        Encode_COUP(ctx) ||
        Encode_PNEUM(ctx) ||
        Encode_PSYCH(ctx) ||
        Encode_PSALM(ctx))
    {
        return;
    }

    Encode_PB(ctx);

    MetaphAdd(ctx, "P");
}