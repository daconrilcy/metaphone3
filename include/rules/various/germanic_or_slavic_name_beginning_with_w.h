#ifndef GERMANIC_OR_SLAVIC_NAME_BEGINNING_WITH_W_H
#define GERMANIC_OR_SLAVIC_NAME_BEGINNING_WITH_W_H

#include "metaphone3.h"
#include <stdbool.h>

/**
 * Test whether the word in question
 * is a name of germanic or slavic origin, for
 * the purpose of determining whether to add an
 * alternate encoding of 'V'
 *
 * @return true if germanic or slavic name
 */
bool Germanic_Or_Slavic_Name_Beginning_With_W(Metaphone3 *ctx);

#endif
