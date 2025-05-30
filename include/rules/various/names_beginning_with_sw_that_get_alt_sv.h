#ifndef NAMES_BEGINNING_WITH_SW_THAT_GET_ALT_SV_H
#define NAMES_BEGINNING_WITH_SW_THAT_GET_ALT_SV_H

#include "metaphone3.h"
#include <stdbool.h>

/**
 * Test for names derived from the swedish,
 * dutch, or slavic that should get an alternate
 * pronunciation of 'SV' to match the native
 * version
 *
 * @return true if swedish, dutch, or slavic derived name
 */
bool Names_Beginning_With_SW_That_Get_Alt_SV(Metaphone3 *ctx);

#endif
