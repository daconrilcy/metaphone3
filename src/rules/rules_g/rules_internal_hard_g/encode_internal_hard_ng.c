#include "rules/rules_g/rules_internal_hard_g/encode_internal_hard_ng.h"
#include "utils/string_utils.h"

bool Internal_Hard_NG(Metaphone3 *ctx) {
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;
  int m_length = ctx->m_length;
  const char *w = ctx->m_inWord;

  if ((StringAt(w, (m_current - 3), 4, "DANG", "FANG", "SING", "")
       // exception to exception
       && !StringAt(w, (m_current - 5), 8, "DISINGEN", "")) ||
      StringAt(w, 0, 5, "INGEB", "ENGEB", "") ||
      (StringAt(w, (m_current - 3), 4, "RING", "WING", "HANG", "LONG", "") &&
       !(StringAt(w, (m_current - 4), 5, "CRING", "FRING", "ORANG", "TWING",
                  "CHANG", "PHANG", "") ||
         StringAt(w, (m_current - 5), 6, "SYRING", "") ||
         StringAt(w, (m_current - 3), 7, "RINGENC", "RINGENT", "LONGITU",
                  "LONGEVI", "")
         // e.g. 'longino', 'mastrangelo'
         || (StringAt(w, m_current, 4, "GELO", "GINO", "") &&
             ((m_current + 3) == m_last)))) ||
      (StringAt(w, (m_current - 1), 3, "NGY", "")
       // exceptions to exception
       && !(StringAt(w, (m_current - 3), 5, "RANGY", "MANGY", "MINGY", "") ||
            StringAt(w, (m_current - 4), 6, "SPONGY", "STINGY", "")))) {
    return true;
  }

  return false;
}