#ifndef BUFFER_H
#define BUFFER_H

#include <stddef.h>

// Structure pour gérer une chaîne dynamique (type StringBuffer Java)
typedef struct
{
    char *data;      // Pointeur vers la mémoire de la chaîne
    size_t length;   // Longueur courante (hors '\0')
    size_t capacity; // Taille allouée
} Buffer;

// Crée un nouveau buffer avec une capacité initiale
Buffer *Buffer_new(size_t initial_capacity);

// Libère toute la mémoire utilisée par le buffer
void Buffer_free(Buffer *buf);

// Ajoute une chaîne à la fin du buffer
void Buffer_append(Buffer *buf, const char *str);

// Ajoute un caractère à la fin du buffer
void Buffer_append_char(Buffer *buf, char c);

// Réinitialise le buffer à vide (ne libère pas la mémoire)
void Buffer_clear(Buffer *buf);

// Récupère la chaîne sous-jacente (toujours '\0' terminée)
const char *Buffer_data(Buffer *buf);

// Retourne la longueur courante (nombre de caractères, hors '\0')
size_t Buffer_length(Buffer *buf);

// Retourne le dernier caractere du buffer
char Buffer_last_char(Buffer *buf);

#endif
