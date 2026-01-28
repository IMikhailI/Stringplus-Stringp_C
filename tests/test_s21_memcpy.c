#include "s21_string_test.h"

START_TEST(test_memcpy_1) {
  s21_size_t n = 7;
  unsigned char src2[10] = "12345";
  unsigned char dst1[10] = "5";
  ck_assert_pstr_eq(memcpy(dst1, src2, n), s21_memcpy(dst1, src2, n));
}
START_TEST(test_memcpy_2) {
  s21_size_t n = 6;
  unsigned char src2[10] = "12345";
  unsigned char dst1[10] = "5";
  ck_assert_pstr_eq(memcpy(dst1, src2, n), s21_memcpy(dst1, src2, n));
}
START_TEST(test_memcpy_3) {
  s21_size_t n = 5;
  unsigned char src2[10] = "12345";
  unsigned char dst1[10] = "5";
  ck_assert_pstr_eq(memcpy(dst1, src2, n), s21_memcpy(dst1, src2, n));
}

Suite *s21_string_memcpy_test() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memcpy_test");
  tc_core = tcase_create("CORE");

  tcase_add_test(tc_core, test_memcpy_1);
  tcase_add_test(tc_core, test_memcpy_2);
  tcase_add_test(tc_core, test_memcpy_3);
  suite_add_tcase(s, tc_core);

  return s;
}