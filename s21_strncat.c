#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *s1 = dest;
  char *s2 = (char *)src;
  int j = s21_strlen(dest);
  int len = s21_strlen(src);
  if (len < (int)n) n = len;
  for (int i = 0; (i < (int)n); ++i) {
    s1[j] = s2[i];
    ++j;
  }
  return dest;
}