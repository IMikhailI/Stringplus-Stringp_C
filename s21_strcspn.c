#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int long_str = 0;
  int stop = 0;

  for (const char *str11 = str1; (*str11 && stop != 1); ++str11) {
    int was = 0;
    for (const char *str22 = str2; (*str22 && stop != 1); ++str22) {
      if (*str11 == *str22) {
        was = 1;
        stop = 1;
      }
    }
    if (was) {
      stop = 1;
    } else {
      ++long_str;
    }
  }
  return long_str;
}