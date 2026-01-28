#include "s21_string_test.h"

int main() {
  Suite *stc[] = {s21_string_memchr_test(),
                  s21_string_memcmp_test(),
                  s21_string_memcpy_test(),
                  s21_string_memset_test(),
                  s21_string_strncat_test(),
                  s21_string_strchr_test(),
                  s21_string_strncmp_test(),
                  s21_string_strncpy_test(),
                  s21_string_strcspn_test(),
                  s21_strerror_suite(),
                  s21_string_strlen_test(),
                  s21_string_strpbrk_test(),
                  s21_string_strrchr_test(),
                  s21_string_strstr_test(),
                  s21_string_strtok_test(),
                  s21_string_suite(),
                  sprint_suite(),
                  s21_string_strcpy_test(),
                  NULL};

  for (int i = 0; stc[i]; i++) {
    putchar('\n');
    SRunner *runner = srunner_create(stc[i]);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }

  return 0;
}