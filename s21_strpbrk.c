#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  int stop = 0;

  while (*str1 != '\0' && !stop) {
    const char *str = str2;

    while (*str != '\0' && !stop) {
      if (*str1 == *str) {
        result = (char *)str1;
        stop = 1;
      }
      str++;
    }
    if (!stop) str1++;
  }
  return result;
}
