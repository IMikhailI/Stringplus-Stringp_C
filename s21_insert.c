#include <ctype.h>

#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = s21_NULL;

  if (src && str) {
    s21_size_t src_length = s21_strlen(src);
    s21_size_t str_length = s21_strlen(str);
    s21_size_t new_length = src_length + str_length;

    if (start_index <= src_length) {
      new_str = (char *)malloc(new_length + 1);
      if (new_str) {
        s21_memcpy(new_str, src, start_index);
        s21_memcpy(new_str + start_index, str, str_length);
        s21_memcpy(new_str + start_index + str_length, src + start_index,
                   src_length - start_index + 1);
        new_str[new_length] = '\0';
      }
    }
  }
  return new_str;
}
