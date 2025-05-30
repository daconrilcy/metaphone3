#include "rules/rules_l/encode_silent_l_in_lk_lv.h"
#include "utils/string_utils.h"

bool Encode_Silent_L_In_LK_LV(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  if ((StringAt(w, (m_current - 2), 4, "WALK", "YOLK", "FOLK", "HALF", "TALK",
                "CALF", "BALK", "CALK", "") ||
       (StringAt(w, (m_current - 2), 4, "POLK", "") &&
        !StringAt(w, (m_current - 2), 5, "POLKA", "WALKO", "")) ||
       (StringAt(w, (m_current - 2), 4, "HALV", "") &&
        !StringAt(w, (m_current - 2), 5, "HALVA", "HALVO", "")) ||
       (StringAt(w, (m_current - 3), 5, "CAULK", "CHALK", "BAULK", "FAULK",
                 "") &&
        !StringAt(w, (m_current - 4), 6, "SCHALK", "")) ||
       (StringAt(w, (m_current - 2), 5, "SALVE", "CALVE", "") ||
        StringAt(w, (m_current - 2), 6, "SOLDER", ""))
           // exceptions to above cases where 'L' is usually pronounced
           && !StringAt(w, (m_current - 2), 6, "SALVER", "CALVER", "")) &&
      !StringAt(w, (m_current - 5), 9, "GONSALVES", "GONCALVES", "") &&
      !StringAt(w, (m_current - 2), 6, "BALKAN", "TALKAL", "") &&
      !StringAt(w, (m_current - 3), 5, "PAULK", "CHALF", "")) {
    ctx->m_current++;
    return true;
  }

  return false;
}