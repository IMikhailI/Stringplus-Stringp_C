#include <ctype.h>

#include "s21_string.h"

int is_trim_char(char c, const char *trim_chars) {
  int result = 0;

  if (trim_chars) {
    while (*trim_chars && result == 0) {
      if (c == *trim_chars) {
        result = 1;
      }
      trim_chars++;
    }
  } else {
    result = isspace(c) ? 1 : 0;
  }

  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_trim = s21_NULL;

  if (src) {
    s21_size_t src_length = s21_strlen(src);
    s21_size_t start = 0;
    s21_size_t end = src_length - 1;

    while (start < src_length && is_trim_char(src[start], trim_chars)) {
      start++;
    }
    while (end > start && is_trim_char(src[end], trim_chars)) {
      end--;
    }
    s21_size_t trim_length = (start <= end) ? (end - start + 1) : 0;

    new_trim = (char *)malloc(trim_length + 1);
    if (new_trim) {
      if (trim_length > 0) {
        s21_memcpy(new_trim, src + start, trim_length);
      }
      new_trim[trim_length] = '\0';
    }
  }
  return new_trim;
}
