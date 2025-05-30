#include "rules/rules_e/silent_internal_e.h"
#include "rules/rules_e/e_pronouncing_suffix.h"
#include "rules/rules_e/e_silent_suffix.h"
#include "utils/string_utils.h"

bool Silent_Internal_E(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_length = ctx->m_length;
  int m_last = ctx->m_last;

  // 'olesen' but not 'olen'	RAKE BLAKE
  if ((StringAt(w, 0, 3, "OLE", "") && E_Silent_Suffix(ctx, 3) &&
       !E_Pronouncing_Suffix(ctx, 3)) ||
      (StringAt(w, 0, 4, "BARE", "FIRE", "FORE", "GATE", "HAGE", "HAVE", "HAZE",
                "HOLE", "CAPE", "HUSE", "LACE", "LINE", "LIVE", "LOVE", "MORE",
                "MOSE", "MORE", "NICE", "RAKE", "ROBE", "ROSE", "SISE", "SIZE",
                "WARE", "WAKE", "WISE", "WINE", "") &&
       E_Silent_Suffix(ctx, 4) && !E_Pronouncing_Suffix(ctx, 4)) ||
      (StringAt(w, 0, 5, "BLAKE", "BRAKE", "BRINE", "CARLE", "CLEVE", "DUNNE",
                "HEDGE", "HOUSE", "JEFFE", "LUNCE", "STOKE", "STONE", "THORE",
                "WEDGE", "WHITE", "") &&
       E_Silent_Suffix(ctx, 5) && !E_Pronouncing_Suffix(ctx, 5)) ||
      (StringAt(w, 0, 6, "BRIDGE", "CHEESE", "") && E_Silent_Suffix(ctx, 6) &&
       !E_Pronouncing_Suffix(ctx, 6)) ||
      StringAt(w, (m_current - 5), 7, "CHARLES", "")) {
    return true;
  }

  return false;
}