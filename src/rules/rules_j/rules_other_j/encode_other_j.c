#include "rules/rules_j/rules_other_j/encode_other_j.h"
#include "rules/rules_j/rules_other_j/encode_german_j.h"
#include "rules/rules_j/rules_other_j/encode_j_as_vowel.h"
#include "rules/rules_j/rules_other_j/encode_j_to_j.h"
#include "rules/rules_j/rules_other_j/encode_spanish_j_2.h"

#include "utils/metaph_add.h"
#include "utils/string_utils.h"

void Encode_Other_J(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;
  int m_length = ctx->m_length;

  if (m_current == 0)
  {
    if (Encode_German_J(ctx))
    {
      return;
    }
    else
    {
      if (Encode_J_To_J(ctx))
      {
        return;
      }
    }
  }
  else
  {
    if (Encode_Spanish_J_2(ctx))
    {
      return;
    }
    else if (!Encode_J_As_Vowel(ctx))
    {
      MetaphAdd(ctx, "J");
    }

    // it could happen! e.g. "hajj"
    //  eat redundant 'J'
    if (CharAt(ctx->m_inWord, (ctx->m_current + 1)) == 'J')
    {
      ctx->m_current += 2;
    }
    else
    {
      ctx->m_current++;
    }
  }
}