#include "rules/rules_l/encode_vowel_le_transposition.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_Vowel_LE_Transposition(Metaphone3 *ctx, int save_current)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  // transposition of vowel sound and L occurs in many words,
  // e.g. "bristle", "dazzle", "goggle" => KAKAL
  if (ctx->m_encodeVowels && (save_current > 1) &&
      !IsVowel(CharAt(w, (save_current - 1))) &&
      (CharAt(w, (save_current + 1)) == 'E') &&
      (CharAt(w, (save_current - 1)) != 'L') &&
      (CharAt(w, (save_current - 1)) != 'R')
      // lots of exceptions to this:
      && !IsVowel(CharAt(w, (save_current + 2))) &&
      !StringAt(w, 0, 7, "ECCLESI", "COMPLEC", "COMPLEJ", "ROBLEDO", "") &&
      !StringAt(w, 0, 5, "MCCLE", "MCLEL", "") &&
      !StringAt(w, 0, 6, "EMBLEM", "KADLEC", "") &&
      !(((save_current + 2) == m_last) &&
        StringAt(w, save_current, 3, "LET", "")) &&
      !StringAt(w, save_current, 7, "LETTING", "") &&
      !StringAt(w, save_current, 6, "LETELY", "LETTER", "LETION", "LETIAN",
                "LETING", "LETORY", "") &&
      !StringAt(w, save_current, 5, "LETUS", "LETIV", "") &&
      !StringAt(w, save_current, 4, "LESS", "LESQ", "LECT", "LEDG", "LETE",
                "LETH", "LETS", "LETT", "") &&
      !StringAt(w, save_current, 3, "LEG", "LER", "LEX", "")
      // e.g. "complement" !=> KAMPALMENT
      && !(StringAt(w, save_current, 6, "LEMENT", "") &&
           !(StringAt(w, (m_current - 5), 6, "BATTLE", "TANGLE", "PUZZLE",
                      "RABBLE", "BABBLE", "") ||
             StringAt(w, (m_current - 4), 5, "TABLE", ""))) &&
      !(((save_current + 2) == m_last) &&
        StringAt(w, (save_current - 2), 5, "OCLES", "ACLES", "AKLES", "")) &&
      !StringAt(w, (save_current - 3), 5, "LISLE", "AISLE", "") &&
      !StringAt(w, 0, 4, "ISLE", "") && !StringAt(w, 0, 6, "ROBLES", "") &&
      !StringAt(w, (save_current - 4), 7, "PROBLEM", "RESPLEN", "") &&
      !StringAt(w, (save_current - 3), 6, "REPLEN", "") &&
      !StringAt(w, (save_current - 2), 4, "SPLE", "") &&
      (CharAt(w, (save_current - 1)) != 'H') &&
      (CharAt(w, (save_current - 1)) != 'W'))
  {
    MetaphAdd(ctx, "AL");
    ctx->flag_AL_inversion = true;

    // eat redundant 'L'
    if (CharAt(w, (save_current + 2)) == 'L')
    {
      ctx->m_current = save_current + 3;
    }
    return true;
  }

  return false;
}