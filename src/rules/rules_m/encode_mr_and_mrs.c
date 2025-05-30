#include "rules/rules_m/encode_mr_and_mrs.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_MR_And_MRS(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_length = ctx->m_length;

  if ((m_current == 0) && StringAt(w, m_current, 2, "MR", "")) {
    // exceptions for "mr." and "mrs."
    if ((m_length == 2) && StringAt(w, m_current, 2, "MR", "")) {
      if (ctx->m_encodeVowels) {
        MetaphAdd(ctx, "MASTAR");
      } else {
        MetaphAdd(ctx, "MSTR");
      }
      ctx->m_current += 2;
      return true;
    } else if ((m_length == 3) && StringAt(w, m_current, 3, "MRS", "")) {
      if (ctx->m_encodeVowels) {
        MetaphAdd(ctx, "MASAS");
      } else {
        MetaphAdd(ctx, "MSS");
      }
      ctx->m_current += 3;
      return true;
    }
  }

  return false;
}