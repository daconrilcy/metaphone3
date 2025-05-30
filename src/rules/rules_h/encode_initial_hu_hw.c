#include "rules/rules_h/encode_initial_hu_hw.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_Initial_HU_HW(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // spanish spellings and chinese pinyin transliteration
  if (StringAt(w, 0, 3, "HUA", "HUE", "HWA", ""))
  {
    if (!StringAt(w, m_current, 4, "HUEY", ""))
    {
      MetaphAdd(ctx, "A");

      if (!ctx->m_encodeVowels)
      {
        ctx->m_current += 3;
      }
      else
      {
        ctx->m_current++;
        // don't encode vowels twice
        while (IsVowel(CharAt(w, m_current)) ||
               (CharAt(w, m_current) == 'W'))
        {
          ctx->m_current++;
        }
      }
      return true;
    }
  }

  return false;
}