#include "s21_string_test.h"

START_TEST(test_strpbrk_1) {
  char str[10] = "0123456789";
  char sym[10] = "9876";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
START_TEST(test_strpbrk_2) {
  char str[10] = "012345";
  char sym[10] = "9876";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
START_TEST(test_strpbrk_3) {
  char str[11] = "hello world";
  char sym[10] = "old";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}

Suite *s21_string_strpbrk_test() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strpbrk_test");
  tc_core = tcase_create("CORE");

  tcase_add_test(tc_core, test_strpbrk_1);
  tcase_add_test(tc_core, test_strpbrk_2);
  tcase_add_test(tc_core, test_strpbrk_3);

  suite_add_tcase(s, tc_core);

  return s;
}