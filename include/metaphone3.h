#ifndef METAPHONE3_H
#define METAPHONE3_H

#include <stdbool.h>
#include "buffer.h"

// Structure principale représentant l’encodeur Metaphone3
typedef struct
{
    // ---- Configuration générale ----
    int m_length;        // Longueur du mot à encoder
    int m_metaphLength;  // Longueur max de la clé générée
    bool m_encodeVowels; // Faut-il encoder les voyelles ?
    bool m_encodeExact;  // Mode "exact" (voir spéc Java)

    // ---- Buffers et état interne ----
    char *m_inWord;      // Copie du mot à encoder (toupper, nettoyé)
    Buffer *m_primary;   // Buffer clé primaire
    Buffer *m_secondary; // Buffer clé secondaire

    int m_current; // Index courant sur m_inWord
    int m_last;    // Index du dernier caractère de m_inWord

    // ---- Flags spécifiques (exemple) ----
    bool flag_AL_inversion; // Exemple de flag métier

    // TODO: Ajouter d’autres flags ou états si besoin (voir Java)
} Metaphone3;

// Crée et initialise une structure Metaphone3 à partir d’un mot source
Metaphone3 *Metaphone3_new(const char *word, bool encodeVowels, bool encodeExact, int metaphLength);

// Libère toutes les ressources associées à l’instance
void Metaphone3_free(Metaphone3 *ctx);

// Lance l’encodage Metaphone3 sur le mot et remplit les buffers
void Metaphone3_encode(Metaphone3 *ctx);

// Accès aux clés générées
const char *Metaphone3_primary(Metaphone3 *ctx);
const char *Metaphone3_secondary(Metaphone3 *ctx);
#endif