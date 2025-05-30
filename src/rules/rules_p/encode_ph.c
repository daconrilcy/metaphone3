#include "rules/rules_p/encode_ph.h"
#include "utils/advance_counter.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_PH(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  if (CharAt(w, (m_current + 1)) == 'H') {
    // 'PH' silent in these contexts
    if (StringAt(w, m_current, 9, "PHTHALEIN", "") ||
        ((m_current == 0) && StringAt(w, m_current, 4, "PHTH", "")) ||
        StringAt(w, (m_current - 3), 10, "APOPHTHEGM", "")) {
      MetaphAdd(ctx, "0");
      ctx->m_current += 4;
    }
    // combining forms
    //'sheepherd', 'upheaval', 'cupholder'
    else if ((m_current > 0) &&
             (StringAt(w, (m_current + 2), 3, "EAD", "OLE", "ELD", "ILL", "OLD",
                       "EAP", "ERD", "ARD", "ANG", "ORN", "EAV", "ART", "") ||
              StringAt(w, (m_current + 2), 4, "OUSE", "") ||
              (StringAt(w, (m_current + 2), 2, "AM", "") &&
               !StringAt(w, (m_current - 1), 5, "LPHAM", "")) ||
              StringAt(w, (m_current + 2), 5, "AMMER", "AZARD", "UGGER", "") ||
              StringAt(w, (m_current + 2), 6, "OLSTER", "")) &&
             !StringAt(w, (m_current - 3), 5, "LYMPH", "NYMPH", "")) {
      MetaphAdd(ctx, "P");
      AdvanceCounter(ctx, 3, 2);
    } else {
      MetaphAdd(ctx, "F");
      ctx->m_current += 2;
    }
    return true;
  }

  return false;
}