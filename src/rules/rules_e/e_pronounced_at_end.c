#include "rules/rules_e/e_pronounced_at_end.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"

bool E_Pronounced_At_End(Metaphone3 *ctx)
{
    const char *w = ctx->m_inWord;
    int m_current = ctx->m_current;
    int m_length = ctx->m_length;
    int m_last = ctx->m_last;

    if ((m_current == m_last) &&
        (StringAt(w, (m_current - 6), 7, "STROPHE", "")
         // if a vowel is before the 'E', vowel eater will have eaten it.
         // otherwise, consonant + 'E' will need 'E' pronounced
         || (m_length == 2) || ((m_length == 3) && !IsVowel(CharAt(w, 0)))
         // these german name endings can be relied on to have the 'e' pronounced
         || (StringAt(w, (m_last - 2), 3, "BKE", "DKE", "FKE", "KKE", "LKE",
                      "NKE", "MKE", "PKE", "TKE", "VKE", "ZKE", "") &&
             !StringAt(w, 0, 5, "FINKE", "FUNKE", "") && !StringAt(w, 0, 6, "FRANKE", "")) ||
         StringAt(w, (m_last - 4), 5, "SCHKE", "") ||
         (StringAt(w, 0, 4, "ACME", "NIKE", "CAFE", "RENE", "LUPE", "JOSE", "ESME", "") &&
          (m_length == 4)) ||
         (StringAt(w, 0, 5, "LETHE", "CADRE", "TILDE", "SIGNE", "POSSE", "LATTE", "ANIME", "DOLCE", "CROCE", "ADOBE", "OUTRE", "JESSE", "JAIME", "JAFFE", "BENGE", "RUNGE", "CHILE", "DESME", "CONDE", "URIBE", "LIBRE", "ANDRE", "") &&
          (m_length == 5)) ||
         (StringAt(w, 0, 6, "HECATE", "PSYCHE", "DAPHNE", "PENSKE", "CLICHE", "RECIPE", "TAMALE", "SESAME", "SIMILE", "FINALE", "KARATE", "RENATE", "SHANTE", "OBERLE", "COYOTE", "KRESGE", "STONGE", "STANGE", "SWAYZE", "FUENTE", "SALOME", "URRIBE", "") &&
          (m_length == 6)) ||
         (StringAt(w, 0, 7, "ECHIDNE", "ARIADNE", "MEINEKE", "PORSCHE", "ANEMONE", "EPITOME", "SYNCOPE", "SOUFFLE", "ATTACHE", "MACHETE", "KARAOKE", "BUKKAKE", "VICENTE", "ELLERBE", "VERSACE", "") &&
          (m_length == 7)) ||
         (StringAt(w, 0, 8, "PENELOPE", "CALLIOPE", "CHIPOTLE", "ANTIGONE", "KAMIKAZE", "EURIDICE", "YOSEMITE", "FERRANTE", "") &&
          (m_length == 8)) ||
         (StringAt(w, 0, 9, "HYPERBOLE", "GUACAMOLE", "XANTHIPPE", "") && (m_length == 9)) ||
         (StringAt(w, 0, 10, "SYNECDOCHE", "") && (m_length == 10))))
    {
        return true;
    }

    return false;
}