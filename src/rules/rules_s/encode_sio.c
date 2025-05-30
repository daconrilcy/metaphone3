#include "rules/rules_s/encode_sio.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"
#include "utils/char_utils.h"

bool Encode_SIO(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  // special case, irish name
  if (StringAt(w, 0, 7, "SIOBHAN", ""))
  {
    MetaphAdd(ctx, "X");
    AdvanceCounter(ctx, 3, 1);
    return true;
  }

  if (StringAt(w, (m_current + 1), 3, "ION", ""))
  {
    // e.g. "vision", "version"
    if (IsVowel(CharAt(w, (m_current - 1))) ||
        StringAt(w, (m_current - 2), 2, "ER", "UR", ""))
    {
      MetaphAdd(ctx, "J");
    }
    else // e.g. "declension"
    {
      MetaphAdd(ctx, "X");
    }

    AdvanceCounter(ctx, 3, 1);
    return true;
  }

  return false;
}