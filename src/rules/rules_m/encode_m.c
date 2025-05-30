#include "rules/rules_m/encode_m.h"
#include "rules/rules_m/encode_mac.h"
#include "rules/rules_m/encode_mpt.h"
#include "rules/rules_m/encode_mr_and_mrs.h"
#include "rules/rules_m/encode_silent_m_at_beginning.h"
#include "rules/rules_m/rules_mb/encode_mb.h"

#include "utils/metaph_add.h"

void Encode_M(Metaphone3 *ctx) {
  if (Encode_Silent_M_At_Beginning(ctx) || Encode_MR_And_MRS(ctx) ||
      Encode_MAC(ctx) || Encode_MPT(ctx)) {
    return;
  }

  // Silent 'B' should really be handled
  // under 'B", not here under 'M'!
  Encode_MB(ctx);

  MetaphAdd(ctx, "M");
}