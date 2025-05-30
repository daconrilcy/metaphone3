#include "rules/rules_s/encode_sch.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_SCH(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  // these words were combining forms many centuries ago
  if (StringAt(w, (m_current + 1), 2, "CH", "")) {
    if ((m_current > 0)
        // e.g. "mischief", "escheat"
        && (StringAt(w, (m_current + 3), 3, "IEF", "EAT", "")
            // e.g. "mischance"
            || StringAt(w, (m_current + 3), 4, "ANCE", "ARGE", "")
            // e.g. "eschew"
            || StringAt(w, 0, 6, "ESCHEW", ""))) {
      MetaphAdd(ctx, "S");
      ctx->m_current++;
      return true;
    }

    // Schlesinger's rule
    // dutch, danish, italian, greek origin, e.g. "school", "schooner",
    // "schiavone", "schiz-"
    if ((StringAt(w, (m_current + 3), 2, "OO", "ER", "EN", "UY", "ED", "EM",
                  "IA", "IZ", "IS", "OL", "") &&
         !StringAt(w, m_current, 6, "SCHOLT", "SCHISL", "SCHERR", "")) ||
        StringAt(w, (m_current + 3), 3, "ISZ", "") ||
        (StringAt(w, (m_current - 1), 6, "ESCHAT", "ASCHIN", "ASCHAL", "ISCHAE",
                  "ISCHIA", "") &&
         !StringAt(w, (m_current - 2), 8, "FASCHING", "")) ||
        (StringAt(w, (m_current - 1), 5, "ESCHI", "") &&
         ((m_current + 3) == m_last)) ||
        (CharAt(w, (m_current + 3)) == 'Y')) {
      // e.g. "schermerhorn", "schenker", "schistose"
      if (StringAt(w, (m_current + 3), 2, "ER", "EN", "IS", "") &&
          (((m_current + 4) == m_last) ||
           StringAt(w, (m_current + 3), 3, "ENK", "ENB", "IST", ""))) {
        MetaphAddAlt(ctx, "X", "SK");
      } else {
        MetaphAdd(ctx, "SK");
      }
      ctx->m_current += 3;
      return true;
    } else {
      MetaphAdd(ctx, "X");
      ctx->m_current += 3;
      return true;
    }
  }

  return false;
}