#include "rules/rules_p/encode_coup.h"
#include "utils/string_utils.h"

bool Encode_COUP(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  //'coup'
  if ((m_current == m_last) && StringAt(w, (m_current - 3), 4, "COUP", "") &&
      !StringAt(w, (m_current - 5), 6, "RECOUP", ""))
  {
    ctx->m_current++;
    return true;
  }

  return false;
}