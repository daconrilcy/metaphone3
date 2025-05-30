#include "rules/rules_c/rules_ch/encode_greek_ch_initial.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_Greek_CH_Initial(Metaphone3 *ctx) {
  int cur = ctx->m_current, last = ctx->m_last, len = ctx->m_length;
  const char *w = ctx->m_inWord;

  bool found =
      StringAt(w, cur, 6, "CHAMOM", "CHARAC", "CHARIS", "CHARTO", "CHARTU",
               "CHARYB", "CHRIST", "CHEMIC", "CHILIA", "") ||

      // Exclure "CHEMIN", "ANCHONDO"
      (StringAt(w, cur, 5, "CHEMI", "CHEMO", "CHEMU", "CHEMY", "CHOND", "CHONA",
                "CHONI", "CHOIR", "CHASM", "CHARO", "CHROM", "CHROI", "CHAMA",
                "CHALC", "CHALD", "CHAET", "CHIRO", "CHILO", "CHELA", "CHOUS",
                "CHEIL", "CHEIR", "CHEIM", "CHITI", "CHEOP", "") &&
       !StringAt(w, cur, 6, "CHEMIN", "") &&
       (cur >= 2 ? !StringAt(w, cur - 2, 8, "ANCHONDO", "") : true)) ||

      (StringAt(w, cur, 5, "CHISM", "CHELI", "") &&
       !(StringAt(w, 0, 8, "MACHISMO", "") ||
         StringAt(w, 0, 10, "REVANCHISM", "") ||
         StringAt(w, 0, 9, "RICHELIEU", "") ||
         (StringAt(w, 0, 5, "CHISM", "") && (len == 5)) ||
         StringAt(w, 0, 6, "MICHEL", ""))) ||

      (StringAt(w, cur, 4, "CHOR", "CHOL", "CHYM", "CHYL", "CHLO", "CHOS",
                "CHUS", "CHOE", "") &&
       !StringAt(w, 0, 6, "CHOLLO", "CHOLLA", "CHORIZ", "")) ||

      (StringAt(w, cur, 4, "CHAO", "") && ((cur + 3) != last)) ||

      (StringAt(w, cur, 4, "CHIA", "") &&
       !(StringAt(w, 0, 10, "APPALACHIA", "") ||
         StringAt(w, 0, 7, "CHIAPAS", ""))) ||

      StringAt(w, cur, 7, "CHIMERA", "CHIMAER", "CHIMERI", "") ||

      ((cur == 0) && StringAt(w, cur, 5, "CHAME", "CHELO", "CHITO", "")) ||

      // OCHETE à la fin du mot (cur-1 >= 0 !)
      ((((cur + 4) == last) || ((cur + 5) == last)) &&
       (cur >= 1 ? StringAt(w, cur - 1, 6, "OCHETE", "") : false));

  // Exclusions ("CHORT", "CHOSE", "CROCHET", "CHEMISE", ...)
  if (found &&
      !((StringAt(w, 0, 5, "CHORE", "CHOLO", "CHOLA", "") && (len == 5)) ||
        StringAt(w, cur, 5, "CHORT", "CHOSE", "") ||
        (cur >= 3 ? StringAt(w, cur - 3, 7, "CROCHET", "") : false) ||
        StringAt(w, 0, 7, "CHEMISE", "CHARISE", "CHARISS", "CHAROLE", ""))) {
    // "CHR/L-" => primaire seulement, sinon primaire+secondaire
    if (StringAt(w, cur + 2, 1, "R", "L", "")) {
      MetaphAdd(ctx, "K");
    } else {
      MetaphAddAlt(ctx, "K", "X");
    }
    ctx->m_current += 2;
    return true;
  }

  return false;
}
