#include "rules/rules_k.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_Silent_K(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // skip this except for special cases
  if ((m_current == 0) && StringAt(w, m_current, 2, "KN", ""))
  {
    if (!(StringAt(w, (m_current + 2), 5, "ESSET", "IEVEL", "") ||
          StringAt(w, (m_current + 2), 3, "ISH", "")))
    {
      ctx->m_current += 1;
      return true;
    }
  }

  // e.g. "know", "knit", "knob"
  if ((StringAt(w, (m_current + 1), 3, "NOW", "NIT", "NOT", "NOB", "")
       // exception, "slipknot" => SLPNT but "banknote" => PNKNT
       && !StringAt(w, 0, 8, "BANKNOTE", "")) ||
      StringAt(w, (m_current + 1), 4, "NOCK", "NUCK", "NIFE", "NACK", "") ||
      StringAt(w, (m_current + 1), 5, "NIGHT", ""))
  {
    // N already encoded before
    // e.g. "penknife"
    if ((m_current > 0) && CharAt(w, (m_current - 1)) == 'N')
    {
      ctx->m_current += 2;
    }
    else
    {
      ctx->m_current++;
    }

    return true;
  }

  return false;
}

void Encode_K(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  if (!Encode_Silent_K(ctx))
  {
    MetaphAdd(ctx, "K");

    // eat redundant 'K's and 'Q's
    if ((CharAt(w, (m_current + 1)) == 'K') ||
        (CharAt(w, (m_current + 1)) == 'Q'))
    {
      ctx->m_current += 2;
    }
    else
    {
      ctx->m_current++;
    }
  }
}