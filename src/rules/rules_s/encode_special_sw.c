#include "rules/rules_s/encode_special_sw.h"
#include "rules/various/names_beginning_with_sw_that_get_alt_sv.h"
#include "rules/various/names_beginning_with_sw_that_get_alt_xv.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_Special_SW(Metaphone3 *ctx) {
  if (ctx->m_current == 0) {
    //
    if (Names_Beginning_With_SW_That_Get_Alt_SV(ctx)) {
      MetaphAddAlt(ctx, "S", "SV");
      ctx->m_current += 2;
      return true;
    }

    //
    if (Names_Beginning_With_SW_That_Get_Alt_XV(ctx)) {
      MetaphAddAlt(ctx, "S", "XV");
      ctx->m_current += 2;
      return true;
    }
  }

  return false;
}