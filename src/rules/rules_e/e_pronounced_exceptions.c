#include "rules/rules_e/e_pronounced_exceptions.h"
#include "utils/string_utils.h"

bool E_Pronounced_Exceptions(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;
  int m_length = ctx->m_length;
  int m_last = ctx->m_last;

  // greek names e.g. "herakles" or hispanic names e.g. "robles", where 'e' is
  // pronounced, other exceptions
  if ((((m_current + 1) == m_last) &&
       (StringAt(w, (m_current - 3), 5, "OCLES", "ACLES", "AKLES", "") ||
        StringAt(w, 0, 4, "INES", "") ||
        StringAt(w, 0, 5, "LOPES", "ESTES", "GOMES", "NUNES", "ALVES", "ICKES",
                 "INNES", "PERES", "WAGES", "NEVES", "BENES", "DONES", "") ||
        StringAt(w, 0, 6, "CORTES", "CHAVES", "VALDES", "ROBLES", "TORRES",
                 "FLORES", "BORGES", "NIEVES", "MONTES", "SOARES", "VALLES",
                 "GEDDES", "ANDRES", "VIAJES", "CALLES", "FONTES", "HERMES",
                 "ACEVES", "BATRES", "MATHES", "") ||
        StringAt(w, 0, 7, "DELORES", "MORALES", "DOLORES", "ANGELES", "ROSALES",
                 "MIRELES", "LINARES", "PERALES", "PAREDES", "BRIONES",
                 "SANCHES", "CAZARES", "REVELES", "ESTEVES", "ALVARES",
                 "MATTHES", "SOLARES", "CASARES", "CACERES", "STURGES",
                 "RAMIRES", "FUNCHES", "BENITES", "FUENTES", "PUENTES",
                 "TABARES", "HENTGES", "VALORES", "") ||
        StringAt(w, 0, 8, "GONZALES", "MERCEDES", "FAGUNDES", "JOHANNES",
                 "GONSALES", "BERMUDES", "CESPEDES", "BETANCES", "TERRONES",
                 "DIOGENES", "CORRALES", "CABRALES", "MARTINES", "GRAJALES",
                 "") ||
        StringAt(w, 0, 9, "CERVANTES", "FERNANDES", "GONCALVES", "BENEVIDES",
                 "CIFUENTES", "SIFUENTES", "SERVANTES", "HERNANDES",
                 "BENAVIDES", "") ||
        StringAt(w, 0, 10, "ARCHIMEDES", "CARRIZALES", "MAGALLANES", ""))) ||
      StringAt(w, m_current - 2, 4, "FRED", "DGES", "DRED", "GNES", "") ||
      StringAt(w, (m_current - 5), 7, "PROBLEM", "RESPLEN", "") ||
      StringAt(w, (m_current - 4), 6, "REPLEN", "") ||
      StringAt(w, (m_current - 3), 4, "SPLE", "")) {
    return true;
  }

  return false;
}
