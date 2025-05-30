#include "rules/rules_h/encode_h.h"
#include "rules/rules_h/encode_h_pronounced.h"
#include "rules/rules_h/encode_initial_hs.h"
#include "rules/rules_h/encode_initial_hu_hw.h"
#include "rules/rules_h/encode_initial_silent_h.h"
#include "rules/rules_h/encode_non_initial_silent_h.h"

void Encode_H(Metaphone3 *ctx) {
  if (Encode_Initial_Silent_H(ctx) || Encode_Initial_HS(ctx) ||
      Encode_Initial_HU_HW(ctx) || Encode_Non_Initial_Silent_H(ctx)) {
    return;
  }

  // only keep if first & before vowel or btw. 2 vowels
  if (!Encode_H_Pronounced(ctx)) {
    // also takes care of 'HH'
    ctx->m_current++;
  }
}