#include "s21_string_test.h"

// START_TEST(test_strchr_1) {
//   char str4[11] = "0123456789";
//   int ch4 = '6';
//   ck_assert_pstr_eq(strchr(str4, ch4), s21_strchr(str4, ch4));
// }
// START_TEST(test_strchr_2) {
//   char str4[11] = "0123756789";
//   int ch4 = '7';
//   ck_assert_pstr_eq(strchr(str4, ch4), s21_strchr(str4, ch4));
// }
// START_TEST(test_strchr_3) {
//   char str4[11] = "0123756789";
//   int ch4 = '4';
//   ck_assert_pstr_eq(strchr(str4, ch4), s21_strchr(str4, ch4));
// }
// Suite *s21_string_strchr_test() {
//   Suite *s;
//   TCase *tc_core;

//   s = suite_create("strchr_test");
//   tc_core = tcase_create("CORE");

//   tcase_add_test(tc_core, test_strchr_1);
//   tcase_add_test(tc_core, test_strchr_2);
//   tcase_add_test(tc_core, test_strchr_3);

//   suite_add_tcase(s, tc_core);

//   return s;
// }

START_TEST(test_s21_strchr_1) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_2) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_3) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_4) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_5) {
  char s[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_6) {
  char s[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_7) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_8) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_s21_strchr_9) {
  char src[] = "abrakadabra";
  char find = 'a';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_10) {
  char src[] = "abrakadAbra";
  char find = 'A';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_11) {
  char src[] = "abrakadAbra";
  char find = '1';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_12) {
  char src[] = "abrakadAbra";
  char find = 'Z';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_13) {
  char src[] = "abrakadAbra";
  char find = '3';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_14) {
  char src[] = "";
  char find = '3';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST
Suite *s21_string_strchr_test() {
  Suite *s;
  TCase *tc_s21_strchr;
  s = suite_create("strchr_test");
  tc_s21_strchr = tcase_create("CORE");
  tcase_add_test(tc_s21_strchr, test_s21_strchr_1);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_2);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_3);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_4);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_5);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_6);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_7);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_8);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_9);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_10);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_11);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_12);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_13);
  tcase_add_test(tc_s21_strchr, test_s21_strchr_14);
  suite_add_tcase(s, tc_s21_strchr);

  return s;
}