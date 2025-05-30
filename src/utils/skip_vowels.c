#include "utils/skip_vowels.h"
#include "utils/char_utils.h"
#include "utils/string_utils.h"

int SkipVowels(Metaphone3 *ctx, int at) {
  int m_length = ctx->m_length;
  int m_last = ctx->m_last;
  const char *w = ctx->m_inWord;

  if (at < 0) {
    return 0;
  }

  if (at >= m_length) {
    return m_length;
  }

  char it = CharAt(w, at);

  while (IsVowel(it) || (it == 'W')) {
    if (StringAt(w, at, 4, "WICZ", "WITZ", "WIAK", "") ||
        StringAt(w, (at - 1), 5, "EWSKI", "EWSKY", "OWSKI", "OWSKY", "") ||
        (StringAt(w, at, 5, "WICKI", "WACKI", "") && ((at + 4) == m_last))) {
      break;
    }

    at++;
    if (((CharAt(w, at - 1) == 'W') && (CharAt(w, at) == 'H')) &&
        !(StringAt(w, at, 3, "HOP", "") ||
          StringAt(w, at, 4, "HIDE", "HARD", "HEAD", "HAWK", "HERD", "HOOK",
                   "HAND", "HOLE", "") ||
          StringAt(w, at, 5, "HEART", "HOUSE", "HOUND", "") ||
          StringAt(w, at, 6, "HAMMER", ""))) {
      at++;
    }

    if (at > (m_length - 1)) {
      break;
    }
    it = CharAt(w, at);
  }

  return at;
}