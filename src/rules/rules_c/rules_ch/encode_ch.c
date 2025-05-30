#include "rules/rules_c/rules_ch/encode_ch.h"
#include "rules/rules_c/rules_ch/encode_arch.h"
#include "rules/rules_c/rules_ch/encode_ch_to_h.h"
#include "rules/rules_c/rules_ch/encode_ch_to_x.h"
#include "rules/rules_c/rules_ch/encode_chae.h"
#include "rules/rules_c/rules_ch/encode_english_ch_to_k.h"
#include "rules/rules_c/rules_ch/encode_germanic_ch_to_k.h"
#include "rules/rules_c/rules_ch/encode_greek_ch_initial.h"
#include "rules/rules_c/rules_ch/encode_greek_ch_non_initial.h"
#include "rules/rules_c/rules_ch/encode_silent_ch.h"

// Ajouter ici d'autres sous-règles (ARCH, etc.)
#include "buffer.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_CH(Metaphone3 *ctx) {
  if (!ctx || !ctx->m_inWord)
    return false;
  int cur = ctx->m_current;
  // CH détecté ?
  if (StringAt(ctx->m_inWord, cur, 2, "CH", "")) {
    if (Encode_CHAE(ctx) || Encode_CH_To_H(ctx) || Encode_Silent_CH(ctx) ||
        Encode_ARCH(ctx) || Encode_CH_To_X(ctx) ||
        Encode_English_CH_To_K(ctx) || Encode_Germanic_CH_To_K(ctx) ||
        Encode_Greek_CH_Initial(ctx) || Encode_Greek_CH_Non_Initial(ctx)) {
      return true;
    }
    if (cur > 0) {
      if (StringAt(ctx->m_inWord, 0, 2, "MC", "") && cur == 1) {
        MetaphAdd(ctx, "K");
      } else {
        MetaphAddAlt(ctx, "X", "K");
      }
    } else {
      MetaphAdd(ctx, "X");
    }
    ctx->m_current += 2;
    return true;
  }
  return false;
}