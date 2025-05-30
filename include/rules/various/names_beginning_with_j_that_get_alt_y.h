#ifndef NAMES_BEGINNING_WITH_J_THAT_GET_ALT_Y_H
#define NAMES_BEGINNING_WITH_J_THAT_GET_ALT_Y_H

#include "metaphone3.h"
#include <stdbool.h>

/**
 * Test whether the word in question
 * is a name starting with 'J' that should
 * match names starting with a 'Y' sound.
 * All forms of 'John', 'Jane', etc, get
 * and alt to match e.g. 'Ian', 'Yana'. Joelle
 * should match 'Yael', 'Joseph' should match
 * 'Yusef'. German and slavic last names are
 * also included.
 *
 * @return true if name starting with 'J' that
 * should get an alternate encoding as a vowel
 */
bool Names_Beginning_With_J_That_Get_Alt_Y(Metaphone3 *ctx);

#endif
