#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *str1 = (char *)str;
  for (int i = 0; i < (int)n; i++) {
    str1[i] = (char)c;
  }
  return str1;
}