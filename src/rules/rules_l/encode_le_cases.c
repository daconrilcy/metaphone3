#include "rules/rules_l/encode_le_cases.h"
#include "rules/rules_l/encode_vowel_le_transposition.h"
#include "rules/rules_l/encode_vowel_preserve_vowel_after_l.h"
#include "utils/metaph_add.h"

void Encode_LE_Cases(Metaphone3 *ctx, int save_current) {
  if (Encode_Vowel_LE_Transposition(ctx, save_current)) {
    return;
  } else {
    if (Encode_Vowel_Preserve_Vowel_After_L(ctx, save_current)) {
      return;
    } else {
      MetaphAdd(ctx, "L");
    }
  }
}