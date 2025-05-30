#include "rules/rules_s/encode_silent_french_s_final.h"
#include "utils/string_utils.h"
#include "utils/metaph_add.h"

bool Encode_Silent_French_S_Final(Metaphone3 *ctx)
{
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  // "louis" is an exception because it gets two pronuncuations
  if (StringAt(w, 0, 5, "LOUIS", "") && (m_current == m_last))
  {
    MetaphAddAlt(ctx, "S", "");
    ctx->m_current++;
    return true;
  }

  // french words familiar to americans where final s is silent
  if ((m_current == m_last) &&
          (StringAt(w, 0, 4, "YVES", "") ||
           (StringAt(w, 0, 4, "HORS", "") && (m_current == 3)) ||
           StringAt(w, (m_current - 4), 5, "CAMUS", "YPRES", "") ||
           StringAt(w, (m_current - 5), 6, "MESNES", "DEBRIS", "BLANCS",
                    "INGRES", "CANNES", "") ||
           StringAt(w, (m_current - 6), 7, "CHABLIS", "APROPOS", "JACQUES",
                    "ELYSEES", "OEUVRES", "GEORGES", "DESPRES", "") ||
           StringAt(w, 0, 8, "ARKANSAS", "FRANCAIS", "CRUDITES", "BRUYERES",
                    "") ||
           StringAt(w, 0, 9, "DESCARTES", "DESCHUTES", "DESCHAMPS", "DESROCHES",
                    "DESCHENES", "") ||
           StringAt(w, 0, 10, "RENDEZVOUS", "") ||
           StringAt(w, 0, 11, "CONTRETEMPS", "DESLAURIERS", "")) ||
      ((m_current == m_last) &&
       StringAt(w, (m_current - 2), 2, "AI", "OI", "UI", "") &&
       !StringAt(w, 0, 4, "LOIS", "LUIS", "")))
  {
    ctx->m_current++;
    return true;
  }

  return false;
}