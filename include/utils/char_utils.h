#ifndef CHAR_UTILS_H
#define CHAR_UTILS_H

#include <stdbool.h>
#include "metaphone3.h"

// Vérifie si le caractère passé est une voyelle (en anglais)
bool IsVowel(char c);

// Vérifie si un caractère est une consonne (utile pour certains traitements)
bool IsConsonant(char c);

// Transforme un caractère en majuscule
char ToUpper(char c);

// Transforme un caractère en minuscule
char ToLower(char c);

// Renvoie true si c'est une voyelle à la position idx (ou fin de mot)
bool IsVowelAt(Metaphone3 *ctx, int idx);

#endif