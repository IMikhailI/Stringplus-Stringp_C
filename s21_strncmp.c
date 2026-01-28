#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  const unsigned char *str11 = (const unsigned char *)str1;
  const unsigned char *str22 = (const unsigned char *)str2;
  int dif = 0;
  int stop = 0;
  for (int i = 0; (i < (int)n && stop == 0); i++) {
    if (str11[i] != str22[i]) {
      dif = (str11[i] - str22[i]);
      ++stop;
    }
  }
  return dif;
}