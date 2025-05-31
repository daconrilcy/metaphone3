#include "api/metaphone3_py.h"
#include "api/encode_multi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Retourne une string CSV : "mot,primary,secondary\n"
char *metaphone3_encode_multi_str(
    const char *input, char sep,
    int encodeVowels, int encodeExact, int metaphLength)
{
    EncodedWordList res = encode_multi(input, sep, encodeVowels, encodeExact, metaphLength);

    // Calculer la taille totale à allouer
    size_t total = 1;
    for (int i = 0; i < res.count; ++i)
        total += strlen(res.list[i].mot) + strlen(res.list[i].primary) + strlen(res.list[i].secondary) + 3; // 2 virgules + \n

    char *buf = (char *)malloc(total);
    if (!buf)
    {
        free_encoded_word_list(&res);
        return NULL;
    }
    buf[0] = 0;
    for (int i = 0; i < res.count; ++i)
    {
        strcat(buf, res.list[i].mot);
        strcat(buf, ",");
        strcat(buf, res.list[i].primary);
        strcat(buf, ",");
        strcat(buf, res.list[i].secondary);
        strcat(buf, "\n");
    }

    free_encoded_word_list(&res);
    return buf;
}

void free_result_str(char *ptr)
{
    free(ptr);
}
