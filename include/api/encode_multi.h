#ifndef ENCODE_MULTI_H
#define ENCODE_MULTI_H

#include <stdbool.h>

// Résultat pour un mot
typedef struct
{
    char *mot;
    char *primary;
    char *secondary;
} EncodedWord;

// Résultat global (liste de mots encodés)
typedef struct
{
    EncodedWord *list;
    int count;
} EncodedWordList;

EncodedWordList encode_multi(const char *input, char sep, int metaphLength, bool encodeVowels, bool encodeExact);
void free_encoded_word_list(EncodedWordList *result);

#endif
