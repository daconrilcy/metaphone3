#include "rules/rules_t/encode_ti.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_TI(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  // '-tio-', '-tia-', '-tiu-'
  // except combining forms where T already pronounced e.g 'rooseveltian'
  if ((StringAt(w, (m_current + 1), 2, "IO", "") &&
       !StringAt(w, (m_current - 1), 5, "ETIOL", "")) ||
      StringAt(w, (m_current + 1), 3, "IAL", "") ||
      StringAt(w, (m_current - 1), 5, "RTIUM", "ATIUM", "") ||
      ((StringAt(w, (m_current + 1), 3, "IAN", "") && (m_current > 0)) &&
           !(StringAt(w, (m_current - 4), 8, "FAUSTIAN", "") ||
             StringAt(w, (m_current - 5), 9, "PROUSTIAN", "") ||
             StringAt(w, (m_current - 2), 7, "TATIANA", "") ||
             (StringAt(w, (m_current - 3), 7, "KANTIAN", "GENTIAN", "") ||
              StringAt(w, (m_current - 8), 12, "ROOSEVELTIAN", ""))) ||
       (((m_current + 2) == m_last) &&
        StringAt(w, m_current, 3, "TIA", "")
        // exceptions to above rules where the pronounciation is usually X
        && !(StringAt(w, (m_current - 3), 6, "HESTIA", "MASTIA", "") ||
             StringAt(w, (m_current - 2), 5, "OSTIA", "") ||
             StringAt(w, 0, 3, "TIA", "") ||
             StringAt(w, (m_current - 5), 8, "IZVESTIA", ""))) ||
       StringAt(w, (m_current + 1), 4, "IATE", "IATI", "IABL", "IATO", "IARY",
                "") ||
       StringAt(w, (m_current - 5), 9, "CHRISTIAN", ""))) {
    if (((m_current == 2) && StringAt(w, 0, 4, "ANTI", "")) ||
        StringAt(w, 0, 5, "PATIO", "PITIA", "DUTIA", "")) {
      MetaphAdd(ctx, "T");
    } else if (StringAt(w, (m_current - 4), 8, "EQUATION", "")) {
      MetaphAdd(ctx, "J");
    } else {
      if (StringAt(w, m_current, 4, "TION", "")) {
        MetaphAdd(ctx, "X");
      } else if (StringAt(w, 0, 5, "KATIA", "LATIA", "")) {
        MetaphAddAlt(ctx, "T", "X");
      } else {
        MetaphAddAlt(ctx, "X", "T");
      }
    }

    AdvanceCounter(ctx, 3, 1);
    return true;
  }

  return false;
}