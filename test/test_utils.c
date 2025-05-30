#include "../include/buffer.h"
#include "../include/metaphone3.h"
#include "../include/utils/char_utils.h"
#include "../include/utils/string_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("=== Test char_utils ===\n");
  printf("IsVowel('A') = %d (attendu: 1)\n", IsVowel('A'));
  printf("IsVowel('b') = %d (attendu: 0)\n", IsVowel('b'));
  printf("IsConsonant('C') = %d (attendu: 1)\n", IsConsonant('C'));
  printf("ToUpper('d') = %c (attendu: D)\n", ToUpper('d'));
  printf("ToLower('M') = %c (attendu: m)\n", ToLower('M'));

  printf("\n=== Test string_utils ===\n");
  const char *word = "MICHAEL";
  printf("StringAt(\"%s\", 0, 3, \"MIC\", \"MAC\", \"\") = %d (attendu: 1)\n",
         word, StringAt(word, 0, 3, "MIC", "MAC", ""));
  printf("StringAt(\"%s\", 0, 3, \"BOB\", \"\") = %d (attendu: 0)\n", word,
         StringAt(word, 0, 3, "BOB", ""));
  printf("StrLen(\"MICHAEL\") = %d (attendu: 7)\n", StrLen(word));
  printf("CharAt(\"MICHAEL\", 4) = %c (attendu: A)\n", CharAt(word, 4));

  char *sub = SubString(word, 1, 4);
  printf("SubString(\"MICHAEL\", 1, 4) = %s (attendu: ICH)\n", sub);
  free(sub);

  printf("\n=== Test Buffer ===\n");
  Buffer *buf = Buffer_new(4);
  Buffer_append(buf, "Hello");
  Buffer_append_char(buf, ' ');
  Buffer_append(buf, "World!");
  printf("Buffer: %s (attendu: Hello World!)\n", Buffer_data(buf));
  Buffer_clear(buf);
  Buffer_append(buf, "Test");
  printf("Buffer after clear + append: %s (attendu: Test)\n", Buffer_data(buf));
  Buffer_free(buf);

  printf("\n=== Test Metaphone3 (structure seule) ===\n");
  Metaphone3 *mp3 = Metaphone3_new("MICHAEL", false, false, 16);
  Metaphone3_encode(mp3); // Ne fait rien pour l’instant
  printf("Primary: %s\n", Metaphone3_primary(mp3));
  printf("Secondary: %s\n", Metaphone3_secondary(mp3));
  Metaphone3_free(mp3);

  return 0;
}