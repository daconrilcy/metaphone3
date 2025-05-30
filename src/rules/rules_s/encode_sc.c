#include "rules/rules_s/encode_sc.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_SC(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  if (StringAt(w, m_current, 2, "SC", "")) {
    // exception 'viscount'
    if (StringAt(w, (m_current - 2), 8, "VISCOUNT", "")) {
      ctx->m_current += 1;
      return true;
    }

    // encode "-SC<front vowel>-"
    if (StringAt(w, (m_current + 2), 1, "I", "E", "Y", "")) {
      // e.g. "conscious"
      if (StringAt(w, (m_current + 2), 4, "IOUS", "")
          // e.g. "prosciutto"
          || StringAt(w, (m_current + 2), 3, "IUT", "") ||
          StringAt(w, (m_current - 4), 9, "OMNISCIEN", "")
          // e.g. "conscious"
          || StringAt(w, (m_current - 3), 8, "CONSCIEN", "CRESCEND", "CONSCION",
                      "") ||
          StringAt(w, (m_current - 2), 6, "FASCIS", "")) {
        MetaphAdd(ctx, "X");
      } else if (StringAt(w, m_current, 7, "SCEPTIC", "SCEPSIS", "") ||
                 StringAt(w, m_current, 5, "SCIVV", "SCIRO", "")
                 // commonly pronounced this way in u.s.
                 || StringAt(w, m_current, 6, "SCIPIO", "") ||
                 StringAt(w, (m_current - 2), 10, "PISCITELLI", "")) {
        MetaphAdd(ctx, "SK");
      } else {
        MetaphAdd(ctx, "S");
      }
      ctx->m_current += 2;
      return true;
    }

    MetaphAdd(ctx, "SK");
    ctx->m_current += 2;
    return true;
  }

  return false;
}