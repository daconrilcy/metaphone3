#include "api/encode_multi.h"
#include "metaphone3.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

EncodedWordList encode_multi(const char *input, char sep, bool encodeVowels, bool encodeExact, int metaphLength)
{
    // Compter le nombre de mots pour l’allocation
    int count = 1;
    for (const char *p = input; *p; ++p)
        if (*p == sep)
            count++;

    EncodedWord *results = malloc(count * sizeof(EncodedWord));
    int idx = 0;

    char *tofree = strdup(input);
    char sep_str[2] = {sep, '\0'};
    char *token = strtok(tofree, sep_str);

    while (token != NULL && idx < count)
    {
        if (strlen(token) == 0)
        {
            token = strtok(NULL, sep_str);
            continue;
        }

        Metaphone3 *mp3 = Metaphone3_new(token, encodeVowels, encodeExact, metaphLength);
        Metaphone3_encode(mp3);

        results[idx].mot = strdup(token);
        results[idx].primary = strdup(Metaphone3_primary(mp3));
        results[idx].secondary = strdup(Metaphone3_secondary(mp3));

        Metaphone3_free(mp3);
        idx++;
        token = strtok(NULL, sep_str);
    }
    free(tofree);

    EncodedWordList out = {.list = results, .count = idx};
    return out;
}

// Libération mémoire
void free_encoded_word_list(EncodedWordList *result)
{
    if (!result)
        return;
    for (int i = 0; i < result->count; ++i)
    {
        free(result->list[i].mot);
        free(result->list[i].primary);
        free(result->list[i].secondary);
    }
    free(result->list);
    result->list = NULL;
    result->count = 0;
}
