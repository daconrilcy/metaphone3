#include "rules/rules_n.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_NCE(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  //'acceptance', 'accountancy'
  if (StringAt(w, (m_current + 1), 1, "C", "S", "") &&
      StringAt(w, (m_current + 2), 1, "E", "Y", "I", "") &&
      (((m_current + 2) == m_last) ||
       ((m_current + 3) == m_last)) &&
      (CharAt(w, (m_current + 3)) == 'S'))
  {
    MetaphAdd(ctx, "NTS");
    ctx->m_current += 2;
    return true;
  }

  return false;
}

void Encode_N(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  if (Encode_NCE(ctx))
  {
    return;
  }

  // eat redundant 'N'
  if (CharAt(w, (m_current + 1)) == 'N')
  {
    ctx->m_current += 2;
  }
  else
  {
    ctx->m_current++;
  }

  if (!StringAt(w, (m_current - 3), 8, "MONSIEUR", "")
      // e.g. "aloneness",
      && !StringAt(w, (m_current - 3), 6, "NENESS", ""))
  {
    MetaphAdd(ctx, "N");
  }
}