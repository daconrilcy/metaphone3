#include "rules/rules_c/rules_ch/encode_greek_ch_non_initial.h"
#include "utils/char_utils.h"
#include "utils/metaph_add.h"
#include "utils/string_utils.h"

bool Encode_Greek_CH_Non_Initial(Metaphone3 *ctx) {
  int cur = ctx->m_current, last = ctx->m_last, len = ctx->m_length;
  const char *w = ctx->m_inWord;

  if ((cur >= 2 && StringAt(w, cur - 2, 6, "ORCHID", "NICHOL", "MECHAN",
                            "LICHEN", "MACHIC", "PACHEL", "RACHIF", "RACHID",
                            "RACHIS", "RACHIC", "MICHAL", "")) ||
      (cur >= 3 &&
       StringAt(w, cur - 3, 5, "MELCH", "GLOCH", "TRACH", "TROCH", "BRACH",
                "SYNCH", "PSYCH", "STICH", "PULCH", "EPOCH", "")) ||
      (cur >= 3 && StringAt(w, cur - 3, 5, "TRICH", "") &&
       !(cur >= 5 && StringAt(w, cur - 5, 7, "OSTRICH", ""))) ||
      (cur >= 2 &&
       StringAt(w, cur - 2, 4, "TYCH", "TOCH", "BUCH", "MOCH", "CICH", "DICH",
                "NUCH", "EICH", "LOCH", "DOCH", "ZECH", "WYCH", "") &&
       !(cur >= 4 && StringAt(w, cur - 4, 9, "INDOCHINA", "")) &&
       !(cur >= 2 && StringAt(w, cur - 2, 6, "BUCHON", ""))) ||
      (cur >= 2 && StringAt(w, cur - 2, 5, "LYCHN", "TACHO", "ORCHO", "ORCHI",
                            "LICHO", "")) ||
      ((cur == 1 || cur == 2) &&
       StringAt(w, cur - 1, 5, "OCHER", "ECHIN", "ECHID", "")) ||
      (cur >= 4 &&
       StringAt(w, cur - 4, 6, "BRONCH", "STOICH", "STRYCH", "TELECH", "PLANCH",
                "CATECH", "MANICH", "MALACH", "BIANCH", "DIDACH", "")) ||
      (cur == 1 && StringAt(w, cur - 1, 4, "ICHA", "ICHN", "")) ||
      (cur >= 2 && StringAt(w, cur - 2, 8, "ORCHESTR", "")) ||
      (cur >= 4 && StringAt(w, cur - 4, 8, "BRANCHIO", "BRANCHIF", "")) ||
      (cur >= 1 &&
       StringAt(w, cur - 1, 5, "ACHAB", "ACHAD", "ACHAN", "ACHAZ", "") &&
       !(cur >= 2 && StringAt(w, cur - 2, 7, "MACHADO", "LACHANC", ""))) ||
      (cur >= 1 &&
       StringAt(w, cur - 1, 6, "ACHISH", "ACHILL", "ACHAIA", "ACHENE", "")) ||
      (cur >= 1 && StringAt(w, cur - 1, 7, "ACHAIAN", "ACHATES", "ACHIRAL",
                            "ACHERON", "")) ||
      (cur >= 1 && StringAt(w, cur - 1, 8, "ACHILLEA", "ACHIMAAS", "ACHILARY",
                            "ACHELOUS", "ACHENIAL", "ACHERNAR", "")) ||
      (cur >= 1 &&
       StringAt(w, cur - 1, 9, "ACHALASIA", "ACHILLEAN", "ACHIMENES", "")) ||
      (cur >= 1 && StringAt(w, cur - 1, 10, "ACHIMELECH", "ACHITOPHEL", ""))
      // e.g. 'inchoate'
      || (cur >= 2 && ((cur - 2) == 0) &&
          (StringAt(w, cur - 2, 6, "INCHOA", "")
           // e.g. 'ischemia'
           || StringAt(w, 0, 4, "ISCH", "")))
      // e.g. 'ablimelech', 'antioch', 'pentateuch'
      || ((cur + 1) == last && cur >= 1 &&
          StringAt(w, cur - 1, 1, "A", "O", "U", "E", "") &&
          !(StringAt(w, 0, 7, "DEBAUCH", "") ||
            (cur >= 2 && StringAt(w, cur - 2, 4, "MUCH", "SUCH", "KOCH", "")) ||
            (cur >= 5 && StringAt(w, cur - 5, 7, "OODRICH", "ALDRICH", ""))))) {
    MetaphAddAlt(ctx, "K", "X");
    ctx->m_current += 2;
    return true;
  }
  return false;
}
