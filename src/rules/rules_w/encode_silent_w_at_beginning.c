#include "rules/rules_w/encode_silent_w_at_beginning.h"
#include "utils/string_utils.h"

bool Encode_Silent_W_At_Beginning(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // skip these when at start of word
  if ((m_current == 0) && StringAt(w, m_current, 2, "WR", ""))
  {
    ctx->m_current += 1;
    return true;
  }

  return false;
}