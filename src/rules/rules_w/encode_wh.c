#include "rules/rules_w/encode_wh.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/skip_vowels.h"
#include "utils/string_utils.h"

bool Encode_WH(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  if (StringAt(w, m_current, 2, "WH", ""))
  {
    // cases where it is pronounced as H
    // e.g. 'who', 'whole'
    if ((CharAt(w, (m_current + 2)) == 'O')
        // exclude cases where it is pronounced like a vowel
        && !(StringAt(w, (m_current + 2), 4, "OOSH", "") ||
             StringAt(w, (m_current + 2), 3, "OOP", "OMP", "ORL", "ORT", "") ||
             StringAt(w, (m_current + 2), 2, "OA", "OP", "")))
    {
      MetaphAdd(ctx, "H");
      AdvanceCounter(ctx, 3, 2);
      return true;
    }
    else
    {
      // combining forms, e.g. 'hollowhearted', 'rawhide'
      if (StringAt(w, (m_current + 2), 3, "IDE", "ARD", "EAD", "AWK", "ERD",
                   "OOK", "AND", "OLE", "OOD", "") ||
          StringAt(w, (m_current + 2), 4, "EART", "OUSE", "OUND", "") ||
          StringAt(w, (m_current + 2), 5, "AMMER", ""))
      {
        MetaphAdd(ctx, "H");
        ctx->m_current += 2;
        return true;
      }
      else if (m_current == 0)
      {
        MetaphAdd(ctx, "A");
        ctx->m_current += 2;
        // don't encode vowels twice
        int new_pos = SkipVowels(ctx, ctx->m_current);
        if (new_pos == ctx->m_current)
        {
          ctx->m_current++;
        }
        else
        {
          ctx->m_current = new_pos;
        }
        return true;
      }
    }
    ctx->m_current += 2;
    return true;
  }

  return false;
}
