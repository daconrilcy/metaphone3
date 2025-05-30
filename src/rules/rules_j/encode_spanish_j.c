#include "rules/rules_j/encode_spanish_j.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_Spanish_J(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;
  int m_length = ctx->m_length;

  // obvious spanish, e.g. "jose", "san jacinto"
  if ((StringAt(w, (m_current + 1), 3, "UAN", "ACI", "ALI", "EFE", "ICA", "IME",
                "OAQ", "UAR", "") &&
       !StringAt(w, m_current, 8, "JIMERSON", "JIMERSEN", "")) ||
      (StringAt(w, (m_current + 1), 3, "OSE", "") &&
       ((m_current + 3) == m_last)) ||
      StringAt(w, (m_current + 1), 4, "EREZ", "UNTA", "AIME", "AVIE", "AVIA",
               "") ||
      StringAt(w, (m_current + 1), 6, "IMINEZ", "ARAMIL", "") ||
      (((m_current + 2) == m_last) &&
       StringAt(w, (m_current - 2), 5, "MEJIA", "")) ||
      StringAt(w, (m_current - 2), 5, "TEJED", "TEJAD", "LUJAN", "FAJAR",
               "BEJAR", "BOJOR", "CAJIG", "DEJAS", "DUJAR", "DUJAN", "MIJAR",
               "MEJOR", "NAJAR", "NOJOS", "RAJED", "RIJAL", "REJON", "TEJAN",
               "UIJAN", "") ||
      StringAt(w, (m_current - 3), 8, "ALEJANDR", "GUAJARDO", "TRUJILLO", "") ||
      (StringAt(w, (m_current - 2), 5, "RAJAS", "") && (m_current > 2)) ||
      (StringAt(w, (m_current - 2), 5, "MEJIA", "") &&
       !StringAt(w, (m_current - 2), 6, "MEJIAN", "")) ||
      StringAt(w, (m_current - 1), 5, "OJEDA", "") ||
      StringAt(w, (m_current - 3), 5, "LEIJA", "MINJA", "") ||
      StringAt(w, (m_current - 3), 6, "VIAJES", "GRAJAL", "") ||
      StringAt(w, m_current, 8, "JAUREGUI", "") ||
      StringAt(w, (m_current - 4), 8, "HINOJOSA", "") ||
      StringAt(w, 0, 4, "SAN ", "") ||
      (((m_current + 1) == m_last) &&
       (CharAt(w, (m_current + 1)) == 'O')
       // exceptions
       && !(StringAt(w, 0, 4, "TOJO", "") || StringAt(w, 0, 5, "BANJO", "") ||
            StringAt(w, 0, 6, "MARYJO", "")))) {
    // americans pronounce "juan" as 'wan'
    // and "marijuana" and "tijuana" also
    // do not get the 'H' as in spanish, so
    // just treat it like a vowel in these cases
    if (!(StringAt(w, m_current, 4, "JUAN", "") ||
          StringAt(w, m_current, 4, "JOAQ", ""))) {
      MetaphAdd(ctx, "H");
    } else {
      if (m_current == 0) {
        MetaphAdd(ctx, "A");
      }
    }
    AdvanceCounter(ctx, 2, 1);
    return true;
  }

  // Jorge gets 2nd HARHA. also JULIO, JESUS
  if (StringAt(w, (m_current + 1), 4, "ORGE", "ULIO", "ESUS", "") &&
      !StringAt(w, 0, 6, "JORGEN", "")) {
    // get both consonants for "jorge"
    if (((m_current + 4) == m_last) &&
        StringAt(w, (m_current + 1), 4, "ORGE", "")) {
      if (ctx->m_encodeVowels) {
        MetaphAddAlt(ctx, "JARJ", "HARHA");
      } else {
        MetaphAddAlt(ctx, "JRJ", "HRH");
      }
      AdvanceCounter(ctx, 5, 5);
      return true;
    }

    MetaphAddAlt(ctx, "J", "H");
    AdvanceCounter(ctx, 2, 1);
    return true;
  }

  return false;
}