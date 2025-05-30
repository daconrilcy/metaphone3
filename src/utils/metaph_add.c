#include "utils/metaph_add.h"
#include "buffer.h"
#include "metaphone3.h"
#include <string.h>

// Ajoute dans les deux buffers, ou un secondaire alternatif si besoin
void MetaphAdd(Metaphone3 *ctx, const char *in)
{

  // Clé primaire
  if (!(strcmp(in, "A") == 0 && ctx->m_primary->length > 0 &&
        Buffer_last_char(ctx->m_primary) == 'A'))
  {
    Buffer_append(ctx->m_primary, in);
  }

  // Clé secondaire
  if (!(strcmp(in, "A") == 0 && ctx->m_secondary->length > 0 &&
        Buffer_last_char(ctx->m_secondary) == 'A'))
  {
    Buffer_append(ctx->m_secondary, in);
  }
}

void MetaphAddAlt(Metaphone3 *ctx, const char *main, const char *alt)
{
  // Clé primaire
  if (!(strcmp(main, "A") == 0 && ctx->m_primary->length > 0 &&
        Buffer_last_char(ctx->m_primary) == 'A'))
  {
    Buffer_append(ctx->m_primary, main);
  }

  // Clé secondaire (uniquement si alt n'est pas vide)
  if (!(strcmp(alt, "A") == 0 && ctx->m_secondary->length > 0 &&
        Buffer_last_char(ctx->m_secondary) == 'A'))
  {
    if (alt && alt[0] != '\0')
    {
      Buffer_append(ctx->m_secondary, alt);
    }
  }
}

/**
 * Ajoute un caractère d'encodage dans les buffers selon le mode Exact/Approx
 * (version 4 paramètres)
 *
 * Si le flag m_encodeExact est activé, on ajoute les valeurs "exactes"
 * (mainExact, altExact). Sinon, on ajoute les valeurs "approx" (main, alt).
 *
 * @param ctx       Contexte Metaphone3
 * @param mainExact Chaîne à ajouter à la clé primaire en mode exact
 * @param altExact  Chaîne à ajouter à la clé secondaire en mode exact
 * @param main      Chaîne à ajouter à la clé primaire en mode approx
 * @param alt       Chaîne à ajouter à la clé secondaire en mode approx
 */
void MetaphAddExactApprox(Metaphone3 *ctx, const char *mainExact,
                          const char *altExact, const char *main,
                          const char *alt)
{
  if (ctx->m_encodeExact)
  {
    // Ajoute le code exact (clé primaire/secondaire)
    MetaphAddAlt(ctx, mainExact, altExact);
  }
  else
  {
    // Ajoute le code approx (clé primaire/secondaire)
    MetaphAddAlt(ctx, main, alt);
  }
}

/**
 * Ajoute un caractère d'encodage dans les buffers selon le mode Exact/Approx
 * (version 2 paramètres)
 *
 * Si le flag m_encodeExact est activé, on ajoute la valeur "exacte"
 * (mainExact). Sinon, on ajoute la valeur "approx" (main).
 *
 * @param ctx       Contexte Metaphone3
 * @param mainExact Chaîne à ajouter à la clé primaire et secondaire en mode
 * exact
 * @param main      Chaîne à ajouter à la clé primaire et secondaire en mode
 * approx
 */
void MetaphAddExactApproxSimple(Metaphone3 *ctx, const char *mainExact,
                                const char *main)
{
  if (ctx->m_encodeExact)
  {
    // Ajoute la version exacte dans primary/secondary
    MetaphAdd(ctx, mainExact);
  }
  else
  {
    // Ajoute la version approx dans primary/secondary
    MetaphAdd(ctx, main);
  }
}
