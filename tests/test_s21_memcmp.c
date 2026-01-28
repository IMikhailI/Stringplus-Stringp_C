#include "s21_string_test.h"

START_TEST(test_memcmp_1) {
  s21_size_t n = 10;
  unsigned char src1[15] = "1234567890";
  unsigned char dst[15] = "1234567810";
  ck_assert_int_eq(memcmp(src1, dst, n), s21_memcmp(src1, dst, n));
}

START_TEST(test_memcmp_2) {
  s21_size_t n = 10;
  unsigned char src1[15] = "1234567810";
  unsigned char dst[15] = "1234567810";
  ck_assert_int_eq(memcmp(src1, dst, n), s21_memcmp(src1, dst, n));
}

START_TEST(test_memcmp_3) {
  s21_size_t n = 10;
  unsigned char src1[15] = "qwerty";
  unsigned char dst[15] = "qwert";
  ck_assert_int_eq(memcmp(src1, dst, n), s21_memcmp(src1, dst, n));
}

Suite *s21_string_memcmp_test() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memcmp_test");
  tc_core = tcase_create("CORE");

  tcase_add_test(tc_core, test_memcmp_1);
  tcase_add_test(tc_core, test_memcmp_2);
  tcase_add_test(tc_core, test_memcmp_3);

  suite_add_tcase(s, tc_core);

  return s;
}