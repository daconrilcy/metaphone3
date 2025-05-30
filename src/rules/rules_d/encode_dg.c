#include "rules/rules_d/encode_dg.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"
#include <stdbool.h>

bool Encode_DG(Metaphone3 *ctx)
{
  int cur = ctx->m_current;
  const char *w = ctx->m_inWord;

  if (StringAt(w, cur, 2, "DG", ""))
  {
    // excludes exceptions e.g. 'edgar',
    // or cases where 'g' is first letter of combining form
    // e.g. 'handgun', 'waldglas'
    if (StringAt(w, (cur + 2), 1, "A", "O", "") ||
        // e.g. "midgut"
        StringAt(w, (cur + 1), 3, "GUN", "GUT", "") ||
        // e.g. "handgrip"
        StringAt(w, (cur + 1), 4, "GEAR", "GLAS", "GRIP", "GREN", "GILL",
                 "GRAF", "") ||
        // e.g. "mudgard"
        StringAt(w, (cur + 1), 5, "GUARD", "GUILT", "GRAVE", "GRASS", "") ||
        // e.g. "woodgrouse"
        StringAt(w, (cur + 1), 6, "GROUSE", ""))
    {
      MetaphAddExactApproxSimple(ctx, "DG", "TK");
    }
    else
    {
      // e.g. "edge", "abridgment"
      MetaphAdd(ctx, "J");
    }
    ctx->m_current += 2;
    return true;
  }

  return false;
}