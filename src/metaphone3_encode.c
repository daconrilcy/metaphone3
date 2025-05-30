#include "metaphone3_encode.h"

#include "rules/rules_b.h"
#include "rules/rules_c/encode_c.h"
#include "rules/rules_d/encode_d.h"
#include "rules/rules_f.h"
#include "rules/rules_g/encode_g.h"
#include "rules/rules_h/encode_h.h"
#include "rules/rules_j/encode_j.h"
#include "rules/rules_k.h"
#include "rules/rules_l/encode_l.h"
#include "rules/rules_m/encode_m.h"
#include "rules/rules_n.h"
#include "rules/rules_p/encode_p.h"
#include "rules/rules_q.h"
#include "rules/rules_r/encode_r.h"
#include "rules/rules_s/encode_s.h"
#include "rules/rules_t/encode_t.h"
#include "rules/rules_v.h"
#include "rules/rules_w/encode_w.h"
#include "rules/rules_x/encode_x.h"
#include "rules/rules_z/encode_z.h"
#include "rules/various/encode_vowels.h"

#include "buffer.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

#include <stddef.h>
#include <stdio.h>

void Metaphone3_encode(Metaphone3 *ctx) {
  if (!ctx || !ctx->m_inWord)
    return;
  ctx->flag_AL_inversion = false;
  Buffer_clear(ctx->m_primary);
  Buffer_clear(ctx->m_secondary);

  if (ctx->m_length < 1) {
    return;
  }

  ctx->m_current = 0;

  while (ctx->m_current <= ctx->m_last) {
    char c = ctx->m_inWord[ctx->m_current];
    switch (c) {
    case 'B':
      Encode_B(ctx);
      break;
    case 'ß':
    case 'Ç':
      MetaphAdd(ctx, "S");
      ctx->m_current++;
      break;
    case 'C':
      Encode_C(ctx);
      break;
    case 'D':
      Encode_D(ctx);
      break;
    case 'F':
      Encode_F(ctx);
      break;
    case 'G':
      Encode_G(ctx);
      break;
    case 'H':
      Encode_H(ctx);
      break;
    case 'J':
      Encode_J(ctx);
      break;
    case 'K':
      Encode_K(ctx);
      break;
    case 'L':
      Encode_L(ctx);
      break;
    case 'M':
      Encode_M(ctx);
      break;
    case 'N':
      Encode_N(ctx);
      break;
    case 'Ń':
      MetaphAdd(ctx, "N");
      ctx->m_current++;
      break;
    case 'P':
      Encode_P(ctx);
      break;
    case 'Q':
      Encode_Q(ctx);
      break;
    case 'R':
      Encode_R(ctx);
      break;
    case 'S':
      Encode_S(ctx);
      break;
    case 'T':
      Encode_T(ctx);
      break;
    case 'Đ': // eth
    case 'Ţ': // thorn
      MetaphAdd(ctx, "0");
      ctx->m_current++;
    case 'V':
      Encode_V(ctx);
      break;
    case 'W':
      Encode_W(ctx);
      break;
    case 'X':
      Encode_X(ctx);
      break;
    case '?':
      MetaphAdd(ctx, "X");
      ctx->m_current++;
      break;
    case 'Z':
      Encode_Z(ctx);
      break;
    default:
      if (IsVowel(CharAt(ctx->m_inWord, ctx->m_current))) {
        Encode_Vowels(ctx);
        break;
      }
      ctx->m_current++;
      break;
    }
  }
}
