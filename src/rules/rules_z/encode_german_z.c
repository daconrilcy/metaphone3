#include "rules/rules_z/encode_german_z.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"
#include <string.h>

bool Encode_German_Z(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  if (((m_current == 2) && ((m_current + 1) == m_last) &&
       StringAt(w, (m_current - 2), 4, "NAZI", "")) ||
      StringAt(w, (m_current - 2), 6, "NAZIFY", "MOZART", "") ||
      StringAt(w, (m_current - 3), 4, "HOLZ", "HERZ", "MERZ", "FITZ", "") ||
      (StringAt(w, (m_current - 3), 4, "GANZ", "") &&
       !IsVowel(CharAt(w, (m_current + 1)))) ||
      StringAt(w, (m_current - 4), 5, "STOLZ", "PRINZ", "") ||
      StringAt(w, (m_current - 4), 7, "VENEZIA", "") ||
      StringAt(w, (m_current - 3), 6, "HERZOG", "")
      // german words beginning with "sch-" but not schlimazel, schmooze
      || ((strstr(w, "SCH") != NULL) &&
          !(StringAt(w, (m_last - 2), 3, "IZE", "OZE", "ZEL", ""))) ||
      ((m_current > 0) && StringAt(w, m_current, 4, "ZEIT", "")) ||
      StringAt(w, (m_current - 3), 4, "WEIZ", "")) {
    if ((m_current > 0) && w[m_current - 1] == 'T') {
      MetaphAdd(ctx, "S");
    } else {
      MetaphAdd(ctx, "TS");
    }
    ctx->m_current++;
    return true;
  }

  return false;
}
