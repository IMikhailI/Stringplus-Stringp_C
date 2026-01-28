// #include <string.h>

#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *str11 = (unsigned char *)str1;
  unsigned char *str22 = (unsigned char *)str2;
  int result = 0;
  s21_size_t i = 0;
  while ((i < n) && (result == 0)) {
    if (str11[i] != str22[i]) {
      result = str11[i] - str22[i];
    } else {
      i++;
    }
  }
  return (result);
}

// int main() {
//   s21_size_t n = 1;
//   unsigned char src1[15] = "Z";
//   unsigned char dst[15] = "a";
//   printf("%d\n", memcmp("Z", "a", 1));
//   printf("%d\n", memcmp(src1, dst, n));
//   printf("%d\n\n", s21_memcmp("Z", "a", 1));
// }