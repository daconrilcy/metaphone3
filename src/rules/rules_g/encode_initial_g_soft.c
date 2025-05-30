#include "rules/rules_g/encode_initial_g_soft.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"

bool Initial_G_Soft(Metaphone3 *ctx) {
  int m_current = ctx->m_current;
  const char *w = ctx->m_inWord;

  if (((StringAt(w, (m_current + 1), 2, "EL", "EM", "EN", "EO", "ER", "ES",
                 "IA", "IN", "IO", "IP", "IU", "YM", "YN", "YP", "YR", "EE",
                 "") ||
        StringAt(w, (m_current + 1), 3, "IRA", "IRO", ""))
       // except for smaller set of cases where => K, e.g. "gerber"
       && !(StringAt(w, (m_current + 1), 3, "ELD", "ELT", "ERT", "INZ", "ERH",
                     "ITE", "ERD", "ERL", "ERN", "INT", "EES", "EEK", "ELB",
                     "EER", "") ||
            StringAt(w, (m_current + 1), 4, "ERSH", "ERST", "INSB", "INGR",
                     "EROW", "ERKE", "EREN", "") ||
            StringAt(w, (m_current + 1), 5, "ELLER", "ERDIE", "ERBER", "ESUND",
                     "ESNER", "INGKO", "INKGO", "IPPER", "ESELL", "IPSON",
                     "EEZER", "ERSON", "ELMAN", "") ||
            StringAt(w, (m_current + 1), 6, "ESTALT", "ESTAPO", "INGHAM",
                     "ERRITY", "ERRISH", "ESSNER", "ENGLER", "") ||
            StringAt(w, (m_current + 1), 7, "YNAECOL", "YNECOLO", "ENTHNER",
                     "ERAGHTY", "") ||
            StringAt(w, (m_current + 1), 8, "INGERICH", "EOGHEGAN", ""))) ||
      (IsVowel(CharAt(w, (m_current + 1))) &&
       (StringAt(w, (m_current + 1), 3, "EE ", "EEW", "") ||
        (StringAt(w, (m_current + 1), 3, "IGI", "IRA", "IBE", "AOL", "IDE",
                  "IGL", "") &&
         !StringAt(w, (m_current + 1), 5, "IDEON", "")) ||
        StringAt(w, (m_current + 1), 4, "ILES", "INGI", "ISEL", "") ||
        (StringAt(w, (m_current + 1), 5, "INGER", "") &&
         !StringAt(w, (m_current + 1), 8, "INGERICH", "")) ||
        StringAt(w, (m_current + 1), 5, "IBBER", "IBBET", "IBLET", "IBRAN",
                 "IGOLO", "IRARD", "IGANT", "") ||
        StringAt(w, (m_current + 1), 6, "IRAFFE", "EEWHIZ", "") ||
        StringAt(w, (m_current + 1), 7, "ILLETTE", "IBRALTA", "")))) {
    return true;
  }

  return false;
}