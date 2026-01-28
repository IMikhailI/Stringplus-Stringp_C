#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *str2 = (char *)src;
  s21_size_t i = 0;
  while ((i < n)) {
    ((char *)dest)[i] = ((char *)str2)[i];
    i++;
  }
  return (dest);
}
