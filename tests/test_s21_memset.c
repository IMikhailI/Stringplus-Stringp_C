#include "s21_string_test.h"

START_TEST(test_memset_1) {
  s21_size_t n = 12;
  unsigned char str[14] = "      memset!n";
  ck_assert_pstr_eq(memset(str, '_', n), s21_memset(str, '_', n));
}

START_TEST(test_memset_2) {
  s21_size_t n = 12;
  unsigned char str[14] = "      memset!n";
  int sym = 4;
  ck_assert_pstr_eq(memset(str, sym, n), s21_memset(str, sym, n));
}
START_TEST(test_memset_3) {
  s21_size_t n = 12;
  unsigned char str[12] = "1234567890";
  int sym = 4;
  ck_assert_pstr_eq(memset(str, sym, n), s21_memset(str, sym, n));
}
START_TEST(test_memset_4) {
  s21_size_t n = 3;
  unsigned char str[10] = "1234567890";
  int sym = 4;
  ck_assert_pstr_eq(memset(str, sym, n), s21_memset(str, sym, n));
}
Suite *s21_string_memset_test() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memset_test");
  tc_core = tcase_create("CORE");

  tcase_add_test(tc_core, test_memset_1);
  tcase_add_test(tc_core, test_memset_2);
  tcase_add_test(tc_core, test_memset_3);
  tcase_add_test(tc_core, test_memset_4);
  suite_add_tcase(s, tc_core);

  return s;
}