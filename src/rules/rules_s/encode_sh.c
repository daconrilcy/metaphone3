#include "rules/rules_s/encode_sh.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_SH(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  if (StringAt(w, m_current, 2, "SH", "")) {
    // exception
    if (StringAt(w, (m_current - 2), 8, "CASHMERE", "")) {
      MetaphAdd(ctx, "J");
      ctx->m_current += 2;
      return true;
    }

    // combining forms, e.g. 'clotheshorse', 'woodshole'
    if ((m_current > 0)
        // e.g. "mishap"
        && ((StringAt(w, (m_current + 1), 3, "HAP", "") &&
             ((m_current + 3) == m_last))
            // e.g. "hartsheim", "clothshorse"
            || StringAt(w, (m_current + 1), 4, "HEIM", "HOEK", "HOLM", "HOLZ",
                        "HOOD", "HEAD", "HEID", "HAAR", "HORS", "HOLE", "HUND",
                        "HELM", "HAWK", "HILL", "")
            // e.g. "dishonor"
            || StringAt(w, (m_current + 1), 5, "HEART", "HATCH", "HOUSE",
                        "HOUND", "HONOR", "")
            // e.g. "mishear"
            || (StringAt(w, (m_current + 2), 3, "EAR", "") &&
                ((m_current + 4) == m_last))
            // e.g. "hartshorn"
            || (StringAt(w, (m_current + 2), 3, "ORN", "") &&
                !StringAt(w, (m_current - 2), 7, "UNSHORN", ""))
            // e.g. "newshour" but not "bashour", "manshour"
            || (StringAt(w, (m_current + 1), 4, "HOUR", "") &&
                !(StringAt(w, 0, 7, "BASHOUR", "") ||
                  StringAt(w, 0, 8, "MANSHOUR", "") ||
                  StringAt(w, 0, 6, "ASHOUR", "")))
            // e.g. "dishonest", "grasshopper"
            || StringAt(w, (m_current + 2), 5, "ARMON", "ONEST", "ALLOW",
                        "OLDER", "OPPER", "EIMER", "ANDLE", "ONOUR", "")
            // e.g. "dishabille", "transhumance"
            || StringAt(w, (m_current + 2), 6, "ABILLE", "UMANCE", "ABITUA",
                        ""))) {
      if (!StringAt(w, (m_current - 1), 1, "S", ""))
        MetaphAdd(ctx, "S");
    } else {
      MetaphAdd(ctx, "X");
    }

    ctx->m_current += 2;
    return true;
  }

  return false;
}