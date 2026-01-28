#include "s21_string_test.h"

START_TEST(test_strlen_1) {
  char str[11] = "0123456789";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
START_TEST(test_strlen_2) {
  char str[11] = "01234567";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
START_TEST(test_strlen_3) {
  char str[11] = "01234567";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
Suite *s21_string_strlen_test() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strlen_test");
  tc_core = tcase_create("CORE");

  tcase_add_test(tc_core, test_strlen_1);
  tcase_add_test(tc_core, test_strlen_2);
  tcase_add_test(tc_core, test_strlen_3);
  suite_add_tcase(s, tc_core);

  return s;
}