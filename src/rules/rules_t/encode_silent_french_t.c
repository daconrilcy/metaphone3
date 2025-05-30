#include "rules/rules_t/encode_silent_french_t.h"
#include "utils/advance_counter.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_Silent_French_T(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_last = ctx->m_last;

  // french silent T familiar to americans
  if (((m_current == m_last) &&
       StringAt(w, (m_current - 4), 5, "MONET", "GENET", "CHAUT", "")) ||
      StringAt(w, (m_current - 2), 9, "POTPOURRI", "") ||
      StringAt(w, (m_current - 3), 9, "BOATSWAIN", "") ||
      StringAt(w, (m_current - 3), 8, "MORTGAGE", "") ||
      (StringAt(w, (m_current - 4), 5, "BERET", "BIDET", "FILET", "DEBUT",
                "DEPOT", "PINOT", "TAROT", "") ||
       StringAt(w, (m_current - 5), 6, "BALLET", "BUFFET", "CACHET", "CHALET",
                "ESPRIT", "RAGOUT", "GOULET", "CHABOT", "BENOIT", "") ||
       StringAt(w, (m_current - 6), 7, "GOURMET", "BOUQUET", "CROCHET",
                "CROQUET", "PARFAIT", "PINCHOT", "CABARET", "PARQUET",
                "RAPPORT", "TOUCHET", "COURBET", "DIDEROT", "") ||
       StringAt(w, (m_current - 7), 8, "ENTREPOT", "CABERNET", "DUBONNET",
                "MASSENET", "MUSCADET", "RICOCHET", "ESCARGOT", "") ||
       StringAt(w, (m_current - 8), 9, "SOBRIQUET", "CABRIOLET", "CASSOULET",
                "OUBRIQUET", "CAMEMBERT", "")) &&
          !StringAt(w, (m_current + 1), 2, "AN", "RY", "IC", "OM", "IN", "")) {
    ctx->m_current++;
    return true;
  }

  return false;
}