#include "s21_string_test.h"

START_TEST(test_strerror_1) {
  int err_num = 7;
  ck_assert_pstr_eq(strerror(err_num), s21_strerror(err_num));
}
END_TEST
START_TEST(test_strerror_2) {
  int err_num = 99;
  ck_assert_pstr_eq(strerror(err_num), s21_strerror(err_num));
}
END_TEST
START_TEST(test_strerror_3) {
  int err_num = 150;
  ck_assert_pstr_eq(strerror(err_num), s21_strerror(err_num));
}
END_TEST

START_TEST(test_strerror_4) {
  for (int i = -134; i < 134; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(test_strerror_5) {
  int n = -1;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}

END_TEST

START_TEST(test_strerror_6) {
  for (int i = 134; i < 150; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
  free(strerror(150));
}
END_TEST

Suite *s21_strerror_suite() {
  Suite *s;
  TCase *tc_s21_strerror;
  s = suite_create("strerror_test");
  tc_s21_strerror = tcase_create("CORE");
  tcase_add_test(tc_s21_strerror, test_strerror_1);
  tcase_add_test(tc_s21_strerror, test_strerror_2);
  tcase_add_test(tc_s21_strerror, test_strerror_3);
  tcase_add_test(tc_s21_strerror, test_strerror_4);
  tcase_add_test(tc_s21_strerror, test_strerror_5);
  tcase_add_test(tc_s21_strerror, test_strerror_6);
  suite_add_tcase(s, tc_s21_strerror);

  return s;
}
