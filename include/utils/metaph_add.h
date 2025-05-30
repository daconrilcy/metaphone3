#ifndef METAPH_ADD_H
#define METAPH_ADD_H

#include "metaphone3.h"
#include "buffer.h"

void MetaphAdd(Metaphone3 *ctx, const char *in);
void MetaphAddAlt(Metaphone3 *ctx, const char *main, const char *alt);
void MetaphAddExactApproxSimple(Metaphone3 *ctx, const char *mainExact, const char *main);
void MetaphAddExactApprox(Metaphone3 *ctx, const char *mainExact, const char *altExact, const char *main, const char *alt);

#endif