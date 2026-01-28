#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *str2 = s21_NULL;
  char *token = s21_NULL;
  if (str) {
    str2 = str;
  }
  if (str2 != s21_NULL) {
    while (*str2 != '\0' && s21_strchr(delim, *str2)) str2++;
    if (*str2 != '\0') {
      token = str2;
      while (*str2 != '\0' && !s21_strchr(delim, *str2)) str2++;
      if (*str2 != '\0') {
        *str2 = '\0';
        str2++;
      } else
        str2 = s21_NULL;
    } else
      str2 = s21_NULL;
  }
  return token;
}
