#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdbool.h>
#include <stdarg.h>

// Vérifie si une sous-chaîne de word à partir de start (longueur length)
// correspond à une des chaines données en argument variable.
// Ex : StringAt("MICHAEL", 0, 3, "MIC", "MAC", "") => true
bool StringAt(const char *word, int start, int length, ...);

// Donne la longueur d'une chaîne (wrapper, si tu veux la surcharger ou logger)
int StrLen(const char *str);

// Renvoie la lettre à la position pos, ou '\0' si hors borne
char CharAt(const char *str, int pos);

// Crée une sous-chaîne de str de start (inclusif) à end (exclusif). Retourne une copie malloc (penser à free).
char *SubString(const char *str, int start, int end);

#endif