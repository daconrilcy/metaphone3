#include "rules/rules_g/rules_gh/encode_gh_to_f.h"
#include "rules/rules_g/rules_gh/encode_gh_special_cases.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_GH_To_F(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // the cases covered here would fall under
  // the GH_To_F rule below otherwise
  if (Encode_GH_Special_Cases(ctx)) {
    return true;
  } else {
    // e.g., 'laugh', 'cough', 'rough', 'tough'
    if ((m_current > 2) && (CharAt(w, (m_current - 1)) == 'U') &&
        IsVowel(CharAt(w, (m_current - 2))) &&
        StringAt(w, (m_current - 3), 1, "C", "G", "L", "R", "T", "N", "S",
                 "") &&
        !StringAt(w, (m_current - 4), 8, "BREUGHEL", "FLAUGHER", "")) {
      MetaphAdd(ctx, "F");
      ctx->m_current += 2;
      return true;
    }
  }

  return false;
}