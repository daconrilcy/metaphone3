#include "rules/rules_g/rules_gh/encode_gh_h_part_of_other_word.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_GH_H_Part_Of_Other_Word(Metaphone3 *ctx) {
  // if the 'H' is the beginning of another word or syllable
  if (StringAt(ctx->m_inWord, (ctx->m_current + 1), 4, "HOUS", "HEAD", "HOLE",
               "HORN", "HARN", "")) {
    MetaphAddExactApproxSimple(ctx, "G", "K");
    ctx->m_current += 2;
    return true;
  }

  return false;
}