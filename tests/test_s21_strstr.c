#include "s21_string_test.h"

START_TEST(test_strstr_1) {
  char str6[23] = "0123456b78912345b67891";
  char str7[10] = "891";
  ck_assert_pstr_eq(strstr(str6, str7), s21_strstr(str6, str7));
}
START_TEST(test_strstr_2) {
  char str6[23] = "0123456b78912345b67891";
  char str7[10] = "b67";
  ck_assert_pstr_eq(strstr(str6, str7), s21_strstr(str6, str7));
}
START_TEST(test_strstr_3) {
  char str6[23] = "0123456b78912345b67891";
  char str7[10] = "";
  ck_assert_pstr_eq(strstr(str6, str7), s21_strstr(str6, str7));
}
START_TEST(test_strstr_4) {
  char str6[23] = "0123456b78912345b67891";
  char str7[10] = "56";
  ck_assert_pstr_eq(strstr(str6, str7), s21_strstr(str6, str7));
}
START_TEST(test_strstr_5) {
  char str6[23] = "0123456b78912345b67891";
  char str7[10] = "b7";
  ck_assert_pstr_eq(strstr(str6, str7), s21_strstr(str6, str7));
}

Suite *s21_string_strstr_test() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strstr_test");
  tc_core = tcase_create("CORE");

  tcase_add_test(tc_core, test_strstr_1);
  tcase_add_test(tc_core, test_strstr_2);
  tcase_add_test(tc_core, test_strstr_3);
  tcase_add_test(tc_core, test_strstr_4);
  tcase_add_test(tc_core, test_strstr_5);

  suite_add_tcase(s, tc_core);

  return s;
}