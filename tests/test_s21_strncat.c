#include "s21_string_test.h"

START_TEST(test_strncat_1) {
  s21_size_t n = 3;
  char dest[20] = "Hello, ";
  char src[20] = "world!";
  ck_assert_pstr_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
START_TEST(test_strncat_2) {
  s21_size_t n = 6;
  char dest[20] = "Hello, ";
  char src[10] = "worl";
  ck_assert_pstr_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}

START_TEST(test_strncat_3) {
  s21_size_t n = 10;
  char dest[20] = "Hello, ";
  char src[10] = "worl";
  ck_assert_pstr_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
Suite *s21_string_strncat_test() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncat_test");
  tc_core = tcase_create("CORE");

  tcase_add_test(tc_core, test_strncat_1);
  tcase_add_test(tc_core, test_strncat_2);
  tcase_add_test(tc_core, test_strncat_3);

  suite_add_tcase(s, tc_core);

  return s;
}
