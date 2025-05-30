#include "rules/various/o_silent.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool O_Silent(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  // if "iron" at beginning or end of word and not "irony"
  if ((CharAt(w, m_current) == 'O') &&
      StringAt(w, (m_current - 2), 4, "IRON", "")) {
    if ((StringAt(w, 0, 4, "IRON", "") ||
         (StringAt(w, (m_current - 2), 4, "IRON", "") &&
          (m_last == (m_current + 1)))) &&
        !StringAt(w, (m_current - 2), 6, "IRONIC", "")) {
      return true;
    }
  }

  return false;
}
