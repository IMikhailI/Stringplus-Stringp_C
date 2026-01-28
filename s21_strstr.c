#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t needle_len = s21_strlen(needle);
  char *result = s21_NULL;

  if (needle_len == 0) {
    result = (char *)haystack;
  } else {
    while (*haystack && result == s21_NULL) {
      if (*haystack == *needle &&
          s21_strncmp(haystack, needle, needle_len) == 0) {
        result = (char *)haystack;
      } else {
        haystack++;
      }
    }
  }

  return result;
}