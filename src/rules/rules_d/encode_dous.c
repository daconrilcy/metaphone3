#include "rules/rules_d/encode_dous.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_DOUS(Metaphone3 *ctx) {
  // e.g. "assiduous", "arduous"
  if (StringAt(ctx->m_inWord, (ctx->m_current + 1), 4, "UOUS", "")) {
    MetaphAddExactApprox(ctx, "J", "D", "J", "T");
    AdvanceCounter(ctx, 4, 1);
    return true;
  }

  return false;
}