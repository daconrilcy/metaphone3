#include "rules/rules_c/rules_front_vowel/encode_ci.h"
#include "buffer.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_CI(Metaphone3 *ctx) {
  int cur = ctx->m_current;
  int last = ctx->m_last;
  int len = ctx->m_length;
  const char *w = ctx->m_inWord;

  // Cas avec consonne avant le C
  if (
      // "fettucini", sauf "mancini"
      ((StringAt(w, cur + 1, 3, "INI", "") &&
        !StringAt(w, 0, 7, "MANCINI", "")) &&
       ((cur + 3) == last))
      // "medici"
      || (cur >= 1 && StringAt(w, cur - 1, 3, "ICI", "") && ((cur + 1) == last))
      // "commercial", "provincial", "cistercian"
      || (cur >= 1 &&
          StringAt(w, cur - 1, 5, "RCIAL", "NCIAL", "RCIAN", "UCIUS", ""))
      // "MARCIA"
      || (cur >= 3 && StringAt(w, cur - 3, 6, "MARCIA", ""))
      // "ANCIENT"
      || (cur >= 2 && StringAt(w, cur - 2, 7, "ANCIENT", ""))) {
    MetaphAddAlt(ctx, "X", "S");
    return true;
  }

  // Cas avec voyelle avant C (ou au début)
  if ((StringAt(w, cur, 3, "CIO", "CIE", "CIA", "") &&
       IsVowel(CharAt(w, cur - 1))) ||
      StringAt(w, cur + 1, 3, "IAO", "")) {
    // Exceptions à exclure
    if (!(cur >= 4 && StringAt(w, cur - 4, 8, "COERCION", ""))) {
      // Si suffixes latins ou assimilés
      if (StringAt(w, cur, 4, "CIAN", "CIAL", "CIAO", "CIES", "CIOL", "CION",
                   "") ||
          (cur >= 3 && StringAt(w, cur - 3, 7, "GLACIER", "")) ||
          StringAt(w, cur, 5, "CIENT", "CIENC", "CIOUS", "CIATE", "CIATI",
                   "CIATO", "CIABL", "CIARY", "") ||
          (((cur + 2) == last) && StringAt(w, cur, 3, "CIA", "CIO", "")) ||
          (((cur + 3) == last) && StringAt(w, cur, 3, "CIAS", "CIOS", ""))) {
        // Exceptions à exclure (liste longue)
        if (!((cur >= 4 && StringAt(w, cur - 4, 11, "ASSOCIATION", "")) ||
              StringAt(w, 0, 4, "OCIE", "") ||
              (cur >= 2 && StringAt(w, cur - 2, 5, "LUCIO", "")) ||
              (cur >= 2 && StringAt(w, cur - 2, 6, "MACIAS", "")) ||
              (cur >= 3 && StringAt(w, cur - 3, 6, "GRACIE", "GRACIA", "")) ||
              (cur >= 2 && StringAt(w, cur - 2, 7, "LUCIANO", "")) ||
              (cur >= 3 && StringAt(w, cur - 3, 8, "MARCIANO", "")) ||
              (cur >= 4 && StringAt(w, cur - 4, 7, "PALACIO", "")) ||
              (cur >= 4 && StringAt(w, cur - 4, 9, "FELICIANO", "")) ||
              (cur >= 5 && StringAt(w, cur - 5, 8, "MAURICIO", "")) ||
              (cur >= 7 && StringAt(w, cur - 7, 11, "ENCARNACION", "")) ||
              (cur >= 4 && StringAt(w, cur - 4, 8, "POLICIES", "")) ||
              (cur >= 2 && StringAt(w, cur - 2, 8, "HACIENDA", "")) ||
              (cur >= 6 && StringAt(w, cur - 6, 9, "ANDALUCIA", "")) ||
              (cur >= 2 && StringAt(w, cur - 2, 5, "SOCIO", "SOCIE", "")))) {
          MetaphAddAlt(ctx, "X", "S");
        } else {
          MetaphAddAlt(ctx, "S", "X");
        }
      } else {
        MetaphAddAlt(ctx, "S", "X");
      }
      return true;
    }
  }

  // Exception "coercion"
  if (cur >= 4 && StringAt(w, cur - 4, 8, "COERCION", "")) {
    MetaphAdd(ctx, "J");
    return true;
  }

  return false;
}
