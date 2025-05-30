#include "rules/rules_r/test_silent_r.h"
#include "utils/string_utils.h"

bool Test_Silent_R(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  // test cases where 'R' is silent, either because the
  // word is from the french or because it is no longer pronounced.
  // e.g. "rogier", "monsieur", "surburban"
  if (((m_current == m_last)
       // reliably french word ending
       && StringAt(w, (m_current - 2), 3, "IER", "")
       // e.g. "metier"
       && (StringAt(w, (m_current - 5), 3, "MET", "VIV", "LUC", "")
           // e.g. "cartier", "bustier"
           || StringAt(w, (m_current - 6), 4, "CART", "DOSS", "FOUR", "OLIV",
                       "BUST", "DAUM", "ATEL", "SONN", "CORM", "MERC", "PELT",
                       "POIR", "BERN", "FORT", "GREN", "SAUC", "GAGN", "GAUT",
                       "GRAN", "FORC", "MESS", "LUSS", "MEUN", "POTH", "HOLL",
                       "CHEN", "")
           // e.g. "croupier"
           || StringAt(w, (m_current - 7), 5, "CROUP", "TORCH", "CLOUT",
                       "FOURN", "GAUTH", "TROTT", "DEROS", "CHART", "")
           // e.g. "chevalier"
           || StringAt(w, (m_current - 8), 6, "CHEVAL", "LAVOIS", "PELLET",
                       "SOMMEL", "TREPAN", "LETELL", "COLOMB", "") ||
           StringAt(w, (m_current - 9), 7, "CHARCUT", "") ||
           StringAt(w, (m_current - 10), 8, "CHARPENT", ""))) ||
      StringAt(w, (m_current - 2), 7, "SURBURB", "WORSTED", "") ||
      StringAt(w, (m_current - 2), 9, "WORCESTER", "") ||
      StringAt(w, (m_current - 7), 8, "MONSIEUR", "") ||
      StringAt(w, (m_current - 6), 8, "POITIERS", "")) {
    return true;
  }

  return false;
}