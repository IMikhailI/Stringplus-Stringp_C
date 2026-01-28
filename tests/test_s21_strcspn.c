#include "s21_string_test.h"

START_TEST(test_strcspn_1) {
  char str[10] = "0123456789";
  char sym[10] = "9876";
  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
START_TEST(test_strcspn_2) {
  char str[10] = "012345789";
  char sym[10] = "6";
  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}

Suite *s21_string_strcspn_test() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strcspn_test");
  tc_core = tcase_create("CORE");

  tcase_add_test(tc_core, test_strcspn_1);
  tcase_add_test(tc_core, test_strcspn_2);

  suite_add_tcase(s, tc_core);

  return s;
}