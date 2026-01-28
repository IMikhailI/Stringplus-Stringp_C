#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *str1 = (const unsigned char *)str;

  int stop = 0;
  s21_size_t i = 0;
  while ((i < n) && (stop != 1)) {
    if (*str1 == ((unsigned char)c)) {
      stop = 1;
    } else {
      i++;
      str1++;
    }
  }
  if (stop == 0) str1 = s21_NULL;
  return (void *)str1;
}