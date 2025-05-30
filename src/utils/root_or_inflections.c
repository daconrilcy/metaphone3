#include "utils/root_or_inflections.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Fabrique un mot en concaténant deux chaînes, retourne une copie (penser à free)
static char *concat(const char *a, const char *b)
{
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    char *res = malloc(len_a + len_b + 1);
    if (!res)
        exit(1);
    memcpy(res, a, len_a);
    memcpy(res + len_a, b, len_b);
    res[len_a + len_b] = '\0';
    return res;
}

bool RootOrInflections(const char *inWord, const char *root)
{
    size_t len_root = strlen(root);
    char *test;

    // root + "S"
    test = concat(root, "S");
    if (strcmp(inWord, root) == 0 || strcmp(inWord, test) == 0)
    {
        free(test);
        return true;
    }
    free(test);

    // root + "ES" (sauf si déjà terminé par E)
    if (root[len_root - 1] != 'E')
    {
        test = concat(root, "ES");
        if (strcmp(inWord, test) == 0)
        {
            free(test);
            return true;
        }
        free(test);
    }

    // root + "ED" ou "D"
    if (root[len_root - 1] != 'E')
    {
        test = concat(root, "ED");
    }
    else
    {
        test = concat(root, "D");
    }
    if (strcmp(inWord, test) == 0)
    {
        free(test);
        return true;
    }
    free(test);

    // Si root finit par E, on retire le E pour la suite
    char *short_root = NULL;
    size_t short_len = len_root;
    if (len_root > 0 && root[len_root - 1] == 'E')
    {
        short_len = len_root - 1;
        short_root = malloc(short_len + 1);
        if (!short_root)
            exit(1);
        strncpy(short_root, root, short_len);
        short_root[short_len] = '\0';
    }

    const char *r = short_root ? short_root : root;

    // root + "ING"
    test = concat(r, "ING");
    if (strcmp(inWord, test) == 0)
    {
        free(test);
        if (short_root)
            free(short_root);
        return true;
    }
    free(test);

    // root + "INGLY"
    test = concat(r, "INGLY");
    if (strcmp(inWord, test) == 0)
    {
        free(test);
        if (short_root)
            free(short_root);
        return true;
    }
    free(test);

    // root + "Y"
    test = concat(r, "Y");
    if (strcmp(inWord, test) == 0)
    {
        free(test);
        if (short_root)
            free(short_root);
        return true;
    }
    free(test);

    if (short_root)
        free(short_root);

    return false;
}