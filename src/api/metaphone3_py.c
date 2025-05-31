#include "api/metaphone3_py.h"
#include "api/encode_multi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Retourne une string CSV : "mot,primary,secondary\n" par ligne
char *metaphone3_encode_multi_str(
    const char *input, char sep,
    int encodeVowels, int encodeExact, int metaphLength)
{
    // 1. Encodage multi-mots : on récupère la liste des mots encodés
    EncodedWordList res = encode_multi(input, sep, encodeVowels, encodeExact, metaphLength);

    // 2. Calculer la taille nécessaire pour le buffer de sortie (on surestime un peu pour la sécurité)
    size_t total = 1; // Pour le '\0' final
    for (int i = 0; i < res.count; ++i)
    {
        total += strlen(res.list[i].mot) +
                 strlen(res.list[i].primary) +
                 strlen(res.list[i].secondary) +
                 3; // 2 virgules + 1 saut de ligne par mot
    }

    // 3. Allocation mémoire
    char *buf = (char *)malloc(total);
    if (!buf)
    {
        free_encoded_word_list(&res);
        return NULL;
    }

    // 4. Construction de la chaîne CSV avec snprintf, ligne par ligne
    size_t pos = 0;
    for (int i = 0; i < res.count; ++i)
    {
        // snprintf écrit à partir de buf+pos, dans la place restante
        int written = snprintf(
            buf + pos,    // Où écrire
            total - pos,  // Espace restant
            "%s,%s,%s\n", // Format CSV
            res.list[i].mot,
            res.list[i].primary,
            res.list[i].secondary);

        // Sécurité : vérification écriture réussie et absence de dépassement
        if (written < 0 || (size_t)written >= total - pos)
        {
            // En cas d'erreur ou buffer trop petit (ne doit jamais arriver ici, mais on protège)
            free(buf);
            free_encoded_word_list(&res);
            return NULL;
        }
        pos += (size_t)written;
    }

    // 5. Assure la terminaison par '\0'
    buf[pos] = '\0';

    // 6. Libération mémoire intermédiaire
    free_encoded_word_list(&res);

    // 7. Renvoi du buffer (à libérer par free_result_str)
    return buf;
}

// Fonction de libération (inchangée)
void free_result_str(char *ptr)
{
    free(ptr);
}
