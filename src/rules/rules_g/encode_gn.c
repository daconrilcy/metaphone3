#include "rules/rules_g/encode_gn.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_GN(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_length = ctx->m_length;
  int m_last = ctx->m_last;

  if (CharAt(w, (m_current + 1)) == 'N') {
    // 'align' 'sign', 'resign' but not 'resignation'
    // also 'impugn', 'impugnable', but not 'repugnant'
    if (((m_current > 1) &&
         ((StringAt(w, (m_current - 1), 1, "I", "U", "E", "") ||
           StringAt(w, (m_current - 3), 9, "LORGNETTE", "") ||
           StringAt(w, (m_current - 2), 9, "LAGNIAPPE", "") ||
           StringAt(w, (m_current - 2), 6, "COGNAC", "") ||
           StringAt(w, (m_current - 3), 7, "CHAGNON", "") ||
           StringAt(w, (m_current - 5), 9, "COMPAGNIE", "") ||
           StringAt(w, (m_current - 4), 6, "BOLOGN", ""))
          // Exceptions: following are cases where 'G' is pronounced
          // in "assign" 'g' is silent, but not in "assignation"
          &&
          !(StringAt(w, (m_current + 2), 5, "ATION", "") ||
            StringAt(w, (m_current + 2), 4, "ATOR", "") ||
            StringAt(w, (m_current + 2), 3, "ATE", "ITY", "")
            // exception to exceptions, not pronounced:
            || (StringAt(w, (m_current + 2), 2, "AN", "AC", "IA", "UM", "") &&
                !(StringAt(w, (m_current - 3), 8, "POIGNANT", "") ||
                  StringAt(w, (m_current - 2), 6, "COGNAC", ""))) ||
            StringAt(w, 0, 7, "SPIGNER", "STEGNER", "") ||
            (StringAt(w, 0, 5, "SIGNE", "") && (m_length == 5)) ||
            StringAt(w, (m_current - 2), 5, "LIGNI", "LIGNO", "REGNA", "DIGNI",
                     "WEGNE", "TIGNE", "RIGNE", "REGNE", "TIGNO", "") ||
            StringAt(w, (m_current - 2), 6, "SIGNAL", "SIGNIF", "SIGNAT", "") ||
            StringAt(w, (m_current - 1), 5, "IGNIT", "")) &&
          !StringAt(w, (m_current - 2), 6, "SIGNET", "LIGNEO", "")))
        // not e.g. 'cagney', 'magna'
        || (((m_current + 2) == m_last) &&
            StringAt(w, m_current, 3, "GNE", "GNA", "") &&
            !StringAt(w, (m_current - 2), 5, "SIGNA", "MAGNA", "SIGNE", ""))) {
      MetaphAddExactApprox(w, "N", "GN", "N", "KN");
    } else {
      MetaphAddExactApproxSimple(w, "GN", "KN");
    }
    ctx->m_current += 2;
    return true;
  }
  return false;
}