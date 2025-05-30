#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_GROWTH_FACTOR 2

static void Buffer_ensure_capacity(Buffer *buf, size_t min_capacity) {
  if (buf->capacity >= min_capacity)
    return;
  size_t new_capacity = buf->capacity ? buf->capacity : 8;
  while (new_capacity < min_capacity) {
    new_capacity *= BUFFER_GROWTH_FACTOR;
  }
  char *new_data = realloc(buf->data, new_capacity + 1);
  if (!new_data) {
    fprintf(stderr, "Erreur : échec realloc dans Buffer_ensure_capacity\n");
    exit(1);
  }
  buf->data = new_data;
  buf->capacity = new_capacity;
}

Buffer *Buffer_new(size_t initial_capacity) {
  Buffer *buf = malloc(sizeof(Buffer));
  if (!buf) {
    fprintf(stderr, "Erreur : échec malloc dans Buffer_new\n");
    exit(1);
  }
  buf->capacity = initial_capacity ? initial_capacity : 8;
  buf->length = 0;
  buf->data = malloc(buf->capacity + 1);
  if (!buf->data) {
    free(buf);
    fprintf(stderr, "Erreur : échec malloc data dans Buffer_new\n");
    exit(1);
  }
  buf->data[0] = '\0';
  return buf;
}

void Buffer_free(Buffer *buf) {
  if (buf) {
    if (buf->data)
      free(buf->data);
    free(buf);
  }
}

void Buffer_append(Buffer *buf, const char *str) {
  if (!buf || !str)
    return;
  size_t add_len = strlen(str);
  Buffer_ensure_capacity(buf, buf->length + add_len);
  memcpy(buf->data + buf->length, str, add_len);
  buf->length += add_len;
  buf->data[buf->length] = '\0';
}

void Buffer_append_char(Buffer *buf, char c) {
  if (!buf)
    return;
  Buffer_ensure_capacity(buf, buf->length + 1);
  buf->data[buf->length++] = c;
  buf->data[buf->length] = '\0';
}

void Buffer_clear(Buffer *buf) {
  if (!buf)
    return;
  buf->length = 0;
  if (buf->data)
    buf->data[0] = '\0';
}

const char *Buffer_data(Buffer *buf) { return buf ? buf->data : ""; }

size_t Buffer_length(Buffer *buf) { return buf ? buf->length : 0; }

char Buffer_last_char(Buffer *buf) {
  return (buf->length > 0) ? buf->data[buf->length - 1] : '\0';
}