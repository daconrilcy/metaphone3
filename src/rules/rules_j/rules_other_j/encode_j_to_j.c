#include "rules/rules_j/rules_other_j/encode_j_to_j.h"
#include "rules/various/names_beginning_with_j_that_get_alt_y.h"

#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/skip_vowels.h"
#include "utils/string_utils.h"

#include <stdio.h>
#include <stdbool.h>

bool Encode_J_To_J(Metaphone3 *ctx)
{

  // On récupère le caractère juste après le J
  char charVowelTest = CharAt(ctx->m_inWord, ctx->m_current + 1);
  bool isCharVowel = IsVowel(charVowelTest);

  if (isCharVowel)
  {

    if ((ctx->m_current == 0) && Names_Beginning_With_J_That_Get_Alt_Y(ctx))
    {

      // 'Y' est une voyelle donc on encode "JA" (ou "A" en alt)
      if (ctx->m_encodeVowels)
      {
        MetaphAddAlt(ctx, "JA", "A");
      }
      else
      {
        MetaphAddAlt(ctx, "J", "A");
      }
    }
    else
    {
      if (ctx->m_encodeVowels)
      {
        MetaphAdd(ctx, "JA");
      }
      else
      {
        MetaphAdd(ctx, "J");
      }
    }

    ctx->m_current++;
    int after_skip = SkipVowels(ctx, ctx->m_current);
    if (after_skip == ctx->m_current)
    {
      // Rien n'a bougé, on force à avancer d'un
      ctx->m_current++;
    }
    else
    {
      ctx->m_current = after_skip;
    }
    return true;
  }
  else
  {
    MetaphAdd(ctx, "J");
    ctx->m_current++;
    return true;
  }
}
