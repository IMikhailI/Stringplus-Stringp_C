#include <ctype.h>

#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *str_copy = s21_NULL;

  if (str != s21_NULL) {
    s21_size_t length = s21_strlen(str);
    str_copy = (char *)malloc(length + 1);

    if (str_copy) {
      for (s21_size_t i = 0; i < length; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          str_copy[i] = (str[i] - 'A') + 'a';
        } else {
          str_copy[i] = str[i];
        }
      }
    }
    str_copy[length] = '\0';
  }
  return str_copy;
}
