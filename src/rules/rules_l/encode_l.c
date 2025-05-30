#include "rules/rules_l/encode_l.h"
#include "rules/rules_l/encode_colonel.h"
#include "rules/rules_l/encode_french_ault.h"
#include "rules/rules_l/encode_french_euil.h"
#include "rules/rules_l/encode_french_oulx.h"
#include "rules/rules_l/encode_le_cases.h"
#include "rules/rules_l/encode_lely_to_l.h"
#include "rules/rules_l/encode_ll_as_vowel_cases.h"
#include "rules/rules_l/encode_silent_l_in_lk_lv.h"
#include "rules/rules_l/encode_silent_l_in_lm.h"
#include "rules/rules_l/encode_silent_l_in_ould.h"
#include "rules/rules_l/interpolate_vowel_when_cons_l_at_end.h"

#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_L(Metaphone3 *ctx) {
  // logic below needs to know this
  // after 'm_current' variable changed
  int save_current = ctx->m_current;

  Interpolate_Vowel_When_Cons_L_At_End(ctx);

  if (Encode_LELY_To_L(ctx) || Encode_COLONEL(ctx) || Encode_French_AULT(ctx) ||
      Encode_French_EUIL(ctx) || Encode_French_OULX(ctx) ||
      Encode_Silent_L_In_LM(ctx) || Encode_Silent_L_In_LK_LV(ctx) ||
      Encode_Silent_L_In_OULD(ctx)) {
    return;
  }

  if (Encode_LL_As_Vowel_Cases(ctx)) {
    return;
  }

  Encode_LE_Cases(ctx, save_current);
}