#ifndef METAPHONE3_PY_H
#define METAPHONE3_PY_H

// Cette fonction alloue un buffer (malloc). Il doit être libéré par free_result_str().
char *metaphone3_encode_multi_str(
    const char *input, char sep,
    int encodeVowels, int encodeExact, int metaphLength);

// Libération du buffer alloué par metaphone3_encode_multi_str
void free_result_str(char *ptr);

#endif
