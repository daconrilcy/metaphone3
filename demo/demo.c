#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "api/encode_multi.h"

// Convertit "true"/"1" en true, tout le reste = false
bool str_to_bool(const char *s)
{
    return (strcmp(s, "1") == 0 || strcasecmp(s, "true") == 0);
}

int main(int argc, char *argv[])
{
    if (argc < 6)
    {
        printf("Usage: %s <mots> <separateur> <encodeVowels:0/1> <encodeExact:0/1> <metaphLength>\n", argv[0]);
        printf("Exemple : %s \"London|Edinburgh\" | 0 0 16\n", argv[0]);
        return 1;
    }

    const char *words = argv[1];
    char sep = argv[2][0];
    bool encodeVowels = str_to_bool(argv[3]);
    bool encodeExact = str_to_bool(argv[4]);
    int metaphLength = atoi(argv[5]);

    EncodedWordList result = encode_multi(words, sep, encodeVowels, encodeExact, metaphLength);

    for (int i = 0; i < result.count; ++i)
    {
        printf("Mot           : %s\n", result.list[i].mot);
        printf("Clé primaire  : %s\n", result.list[i].primary);
        printf("Clé secondaire: %s\n\n", result.list[i].secondary);
    }

    free_encoded_word_list(&result);

    return 0;
}
