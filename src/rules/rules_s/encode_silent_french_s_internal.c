#include "rules/rules_s/encode_silent_french_s_internal.h"
#include "utils/string_utils.h"

bool Encode_Silent_French_S_Internal(Metaphone3 *ctx) {
  const char *w = ctx->m_inWord;
  int m_current = ctx->m_current;

  // french words familiar to americans where internal s is silent
  if (StringAt(w, (m_current - 2), 9, "DESCARTES", "") ||
      StringAt(w, (m_current - 2), 7, "DESCHAM", "DESPRES", "DESROCH",
               "DESROSI", "DESJARD", "DESMARA", "DESCHEN", "DESHOTE", "DESLAUR",
               "") ||
      StringAt(w, (m_current - 2), 6, "MESNES", "") ||
      StringAt(w, (m_current - 5), 8, "DUQUESNE", "DUCHESNE", "") ||
      StringAt(w, (m_current - 7), 10, "BEAUCHESNE", "") ||
      StringAt(w, (m_current - 3), 7, "FRESNEL", "") ||
      StringAt(w, (m_current - 3), 9, "GROSVENOR", "") ||
      StringAt(w, (m_current - 4), 10, "LOUISVILLE", "") ||
      StringAt(w, (m_current - 7), 10, "ILLINOISAN", "")) {
    ctx->m_current++;
    return true;
  }

  return false;
}