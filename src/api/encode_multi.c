#include "api/encode_multi.h"
#include "metaphone3.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

EncodedWordList encode_multi(const char *input, char sep, int metaphLength, bool encodeVowels, bool encodeExact)
{
    // Compte le nombre de mots pour l’allocation (nb de séparateurs + 1)
    int count = 1;
    for (const char *p = input; *p; ++p)
        if (*p == sep)
            count++;

    EncodedWord *results = malloc(count * sizeof(EncodedWord));
    int idx = 0;
    // On duplique la chaîne pour la manipuler (split manuel, no strtok)
    char *tofree = strdup(input);
    char *ptr = tofree;

    bool encodeVowelsBool = encodeVowels ? true : false;
    bool encodeExactBool = encodeExact ? true : false;

    while (*ptr && idx < count)
    {
        // Début du token
        char *start = ptr;
        // Va jusqu'au prochain séparateur ou fin de chaîne
        while (*ptr && *ptr != sep)
            ptr++;
        // Sauvegarde le séparateur trouvé
        char old = *ptr;
        *ptr = '\0'; // Coupe pour obtenir un vrai token

        if (strlen(start) > 0)
        { // Ignore les tokens vides
            Metaphone3 *mp3 = Metaphone3_new(start, encodeVowelsBool, encodeExactBool, metaphLength);
            Metaphone3_encode(mp3);

            results[idx].mot = strdup(start);
            results[idx].primary = strdup(Metaphone3_primary(mp3));
            results[idx].secondary = strdup(Metaphone3_secondary(mp3));

            Metaphone3_free(mp3);
            idx++;
        }
        if (old)
            ptr++; // Passe le séparateur pour continuer le split
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
