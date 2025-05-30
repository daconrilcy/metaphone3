#include "utils/string_utils.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool StringAt(const char *word, int start, int length, ...) {
  if (!word)
    return false;
  int word_len = strlen(word);
  if (start < 0 || (start + length) > word_len)
    return false;

  va_list args;
  va_start(args, length);

  const char *test;
  char substr[64]; // Assez pour la plupart des cas Metaphone
  strncpy(substr, word + start, length);
  substr[length] = '\0';

  bool found = false;
  while ((test = va_arg(args, const char *)) && test[0] != '\0') {
    if (strcmp(substr, test) == 0) {
      found = true;
      break;
    }
  }
  va_end(args);
  return found;
}

int StrLen(const char *str) { return str ? (int)strlen(str) : 0; }

char CharAt(const char *str, int pos) {
  if (!str || pos < 0 || pos >= strlen(str))
    return '\0';
  return str[pos];
}

char *SubString(const char *str, int start, int end) {
  if (!str || start < 0 || end < start || end > strlen(str))
    return NULL;
  int len = end - start;
  char *result = malloc(len + 1);
  if (!result)
    return NULL;
  strncpy(result, str + start, len);
  result[len] = '\0';
  return result;
}
