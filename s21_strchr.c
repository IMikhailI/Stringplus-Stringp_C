#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  if (str != s21_NULL) {
    char *str1 = (char *)str;
    int stop = 0;
    for (int i = 0; !stop && i < (int)s21_strlen(str) + 1; i++, str1++) {
      if (*str1 == (char)c) {
        result = str1;
        stop = 1;
      }
    }
  }

  return (result);
}